   | **Function name** | **Function parameters** | **Description** | **Example** |
   | :-- | :-- | :-- | :-- |
   | `twi_init` | None | Initialize TWI unit, enable internal pull-up resistors, and set SCL frequency | `twi_init();` |
   | `twi_start` | Adress, Mode | Start communication on I2C/TWI bus and send address byte | `twi_start(addr, TWI_READ);` |
   | `twi_write` | Data  | Send one data byte to I2C/TWI Slave device. |  |
   | `twi_read_ack` | None | Read one byte from the I2C/TWI Slave device and acknowledge |  |
   | `twi_read_nack` | None | Read one byte from the I2C/TWI Slave device and acknowledge
 *         it with NACK |  |
   | `twi_stop` | NGenerates stop condition on I2C/TWI bus.Generates stop condition on I2C/TWI bus.