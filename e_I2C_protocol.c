

#include "e_I2C_protocol.h"

/*! \brief Initialize the microcontroller for I2C uses
 * \return 1 to confirme the oparation and 0 for an error
 */
void e_i2cp_init(void)
{
	e_i2c_init();
}

void e_i2cp_deinit(void)
{
	e_i2c_deinit();
}

/*! \brief Enable special I2C interrupt
 * \return 1 to confirme the oparation and 0 for an error
 */
void e_i2cp_enable(void)
{
	e_i2c_enable();
}

/*! \brief Disable special I2C interrupt
 * \return 1 to confirme the oparation and 0 for an error
 */
void e_i2cp_disable(void)
{
	e_i2c_disable();
}

/*! \brief Read a specific register on a device
 * \param device_add The address of the device you want information
 * \param reg The register address you want read on the device
 * \return The readed value
 */
char e_i2cp_read(char device_add, char reg)
{
	char error=0;
	char value;
	while(!error)
	{
		error=1;
		error&=e_i2c_start();
		error&=e_i2c_write(device_add);    	// Device address
		error&=e_i2c_write(reg);     		// Register address

		error&=e_i2c_restart();
		error&=e_i2c_write(device_add+1);   // To change data direction ([bit 0]=1)
 		error&=e_i2c_read(&value);    		// read single byte
		e_i2c_nack();						// only 1 byte is being read, so send nack
		e_i2c_stop();             			// end read cycle
		if(error)
			break;
		e_i2c_reset();
	}
	
   	return value;
}


char e_i2cp_write (char device_add, char reg, char value)
{
	char error=0;

	while(!error)
	{
		error=1;
		error&=e_i2c_start();
		error&=e_i2c_write(device_add);		// Writing the device (slave) address
		error&=e_i2c_write(reg);			// Device register address
		error&=e_i2c_write(value);			// Data to device
		error&=e_i2c_stop();				// Ending the communication	
		if(error)
			break;
		e_i2c_reset();
	}
	return error;
}


