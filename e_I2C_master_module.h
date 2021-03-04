

#ifndef _I2C_MASTER_MODULE
#define _I2C_MASTER_MODULE

#include "p30F6014A.h"


#define START			1
#define WRITE			2
#define ACKNOWLEDGE		3
#define READ			4
#define STOP			5
#define RESTART			6
#define ERROR			10
#define OPERATION_OK	0

// -use I2C_init() in your initialisation
// -I2C_enable(void) before anythig else to enable interrupts
// the others functions must be use generate a valide i2c message.

// all the functions return 1 to confirme the oparation and 0 for an error
// in this case, use char I2C_reset(void) and redo the wrong oparation.
// if there is no result, switch of evrything and beginn from the beginning.. :-) 

char e_i2c_init(void);
char e_i2c_deinit(void);
char e_i2c_start(void);
char e_i2c_restart(void);
char e_i2c_ack(void);
char e_i2c_nack(void);
char e_i2c_read(char *buf);
char e_i2c_stop(void);
char e_i2c_write(char byte);
char e_i2c_enable(void);
char e_i2c_disable(void);
char e_i2c_reset(void);


#endif
