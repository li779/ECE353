#include "io_expander.h"

bool io_expander_init(void)
{
    //==============================
      // Configure I2C GPIO Pins
      //==============================  
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
    
      if(gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PCTL_M, IO_EXPANDER_I2C_SDA_PIN_PCTL)== false)
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
    
      if(gpio_config_port_control(IO_EXPANDER_GPIO_BASE, IO_EXPANDER_I2C_SCL_PCTL_M, IO_EXPANDER_I2C_SDA_PIN_PCTL)== false)
      {
        return false;
      }
  
      //  Initialize the I2C peripheral
      if( initializeI2CMaster(IO_EXPANDER_I2C_BASE)!= I2C_OK)
      {
        return false;
      }

      // Set GPIO directions
      io_expander_write_reg(MCP23017_IODIRA_R, 0x00);
      io_expander_write_reg(MCP23017_IODIRB_R, 0xFF);
  
  return true;
}

void io_expander_write_reg(uint8_t reg, uint8_t data)
{
    i2c_status_t status;
    status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
    while (status != I2C_OK) {}
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, reg, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    while (status != I2C_OK) {}
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    while (status != I2C_OK) {}
    return;
}

uint8_t io_expander_read_reg(uint8_t reg)
{
    uint8_t* data;
    i2c_status_t status;
    status = i2cSetSlaveAddr(IO_EXPANDER_I2C_BASE, MCP23017_DEV_ID, I2C_WRITE);
    while (status != I2C_OK) {}
    status = i2cSendByte(IO_EXPANDER_I2C_BASE, reg, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    while (status != I2C_OK) {}
    status = i2cGetByte(IO_EXPANDER_I2C_BASE, data, I2C_MCS_START | I2C_MCS_RUN | I2C_MCS_STOP);
    while (status != I2C_OK) {}
    return *data;
}