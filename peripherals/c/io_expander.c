#include "io_expander.h"

bool io_expander_init(void)
{
      if(gpio_enable_port(IO_EXPANDER_GPIO_BASE) == false)
      {
        return false;
      }
  
      // Configure SCL 
      if(gpio_config_digital_enable(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PIN)== false)
      {
        return false;
      }
    
      if(gpio_config_alternate_function(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PIN)== false)
      {
        return false;
      }
    
      if(gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PCTL_M, IO_EXPANDER_I2C_SCL_PIN_PCTL)== false)
      {
        return false;
      }

      // Configure SDA 
      if(gpio_config_digital_enable(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN)== false)
      {
        return false;
      }
    
      if(gpio_config_open_drain(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN)== false)
      {
        return false;
      }
    
      if(gpio_config_alternate_function(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PIN)== false)
      {
        return false;
      }
    
      if(gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SDA_PCTL_M, IO_EXPANDER_I2C_SDA_PIN_PCTL)== false)
      {
        return false;
      }
  
      //  Initialize the I2C peripheral
      if( initializeI2CMaster(IO_EXPANDER_I2C_BASE)!= I2C_OK)
      {
        return false;
      }
  
  return true;
}

static i2c_status_t set_addr
( 
  uint8_t  reg_address
)
{
  i2c_status_t status;
  
  // Before doing anything, make sure the I2C device is idle
  while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};

  status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE,MCP23017_DEV_ID, I2C_WRITE);
    
    
  if ( status != I2C_OK )
  {
    return status;
  }
  
	i2cSendByte(IO_EXPANDER_I2C_BASE,reg_address ,I2C_MCS_START | I2C_MCS_RUN |I2C_MCS_STOP);

  return status;
}

static i2c_status_t read_data
( 
  uint8_t *data
)
{
  i2c_status_t status;
  
  // Before doing anything, make sure the I2C device is idle
  while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};

  status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_READ);
    
  
  if ( status != I2C_OK )
  {
    return status;
  }

  status = i2cGetByte( IO_EXPANDER_I2C_BASE, data , I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);


  return status;
}

void set_io_expander_GPIO(){
	//while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
	//i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);

  // Send the IODIRA Address
  //i2cSendByte( IO_EXPANDER_I2C_BASE, MCP23017_IODIRA_R, I2C_MCS_START | I2C_MCS_RUN);

  // Set PortA to be outputs
  //i2cSendByte( IO_EXPANDER_I2C_BASE,0, I2C_MCS_RUN | I2C_MCS_STOP);

  // Send the IODIRB Address
  //i2cSendByte( IO_EXPANDER_I2C_BASE, MCP23017_IODIRB_R, I2C_MCS_START | I2C_MCS_RUN);

  // Set PortB to be outputs
  //i2cSendByte( IO_EXPANDER_I2C_BASE, 1, I2C_MCS_RUN | I2C_MCS_STOP);
	io_expander_write_reg(MCP23017_IODIRA_R,0x00);
	io_expander_write_reg(MCP23017_IODIRB_R,0xff);
}

void io_expander_write_reg(uint8_t reg, uint8_t data)
{
    i2c_status_t status;
	
		while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
    status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
			
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, reg, I2C_MCS_START | I2C_MCS_RUN);
			
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_RUN | I2C_MCS_STOP);
			
    return;
}

uint8_t io_expander_read_reg(uint8_t reg)
{
    uint8_t* data;
    i2c_status_t status;
    status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
    while (status != I2C_OK) {}
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, reg, I2C_MCS_START | I2C_MCS_RUN);
    while (status != I2C_OK) {}
		status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_READ);
    while (status != I2C_OK) {}
    status = i2cGetByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    while (status != I2C_OK) {}
    return *data;
}
