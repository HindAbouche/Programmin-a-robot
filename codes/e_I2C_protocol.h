

#ifndef _I2C_PROTOCOL
#define _I2C_PROTOCOL

//#include "e_I2C_master_module.h"
#include "e_epuck_ports.h"


//public interface

// use void e_i2cp_init(void); in your initialisation. no interrupt is enable
// use void e_i2cp_enable(void); before any other operation to enable the interrupts
// use e_i2cp_write,I2Cp_read to write or read in the Camera registers

void e_i2cp_init(void);
void e_i2cp_deinit(void);
char e_i2cp_write (char device_add,char reg, char value);
char e_i2cp_read(char device_add,char reg);
char e_i2cp_read_string(char device_add, unsigned char read_buffer[], char start_address, char string_length);
char e_i2cp_write_string (char device_add, unsigned char write_buffer[], char start_address, char string_length);
void e_i2cp_enable(void);
void e_i2cp_disable(void);

#endif
