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
			
			// Set up GPIO pins
			set_io_expander_GPIO();
  
  return true;
}

/*static i2c_status_t set_addr
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
}*/

/*static i2c_status_t read_data
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
}*/

void set_io_expander_GPIO(){
	
		io_expander_write_reg(MCP23017_IODIRA_R,0x00);
		io_expander_write_reg(MCP23017_IODIRB_R,0xFF);
		io_expander_write_reg(MCP23017_GPPUB_R, 0xFF);
	
		// Configure PF0 - used to detect GPIOB_reg interrupt
		gpio_enable_port(IO_EXPANDER_IRQ_GPIO_BASE);
		gpio_config_digital_enable(IO_EXPANDER_IRQ_GPIO_BASE, IO_EXPANDER_IRQ_PIN_NUM);
		gpio_config_enable_input(IO_EXPANDER_IRQ_GPIO_BASE, IO_EXPANDER_IRQ_PIN_NUM);
		gpio_config_falling_edge_irq(IO_EXPANDER_IRQ_GPIO_BASE, IO_EXPANDER_IRQ_PIN_NUM);
		
		// Configure MCP23017 interrupt enable
		io_expander_write_reg(MCP23017_GPINTENB_R, 0xFF);	// Interrupt enabled for GPIOB pins
		io_expander_write_reg(MCP23017_INTCONB_R, 0xFF);	// Interrupt happens whether the button is pressed / released
		io_expander_write_reg(MCP23017_IOCONB_R, 0x00);		// Active-low interrupt
	
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

uint8_t io_expander_read_reg(uint8_t reg, uint8_t *data)
{
    i2c_status_t status;
	
		while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
	
		status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
			
		//while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
			
		status = i2cSendByte(IO_EXPANDER_I2C_BASE, MCP23017_GPIOB_R, I2C_MCS_START | I2C_MCS_RUN);
				
		//while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
		
		status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_READ);
			
		//while ( I2CMasterBusy(IO_EXPANDER_I2C_BASE)) {};
	
		status = i2cGetByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
			
    return 0xff;
}
