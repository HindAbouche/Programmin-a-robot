#include "e_epuck_ports.h"

#define DELAY 50000



void demo0() {

	long timer = 0;



	while (1) {

		LED0 = 0; 
		LED1 = 0; 
		LED2 = 0; 
		LED3 = 0;
		LED4 = 0; 
		LED5 = 0; 
		LED6 = 0; 
		LED7 = 0;

		for(timer = 0; timer < DELAY; timer++);

		LED0 = 1; 
		LED1 = 1; 
		LED2 = 1; 
		LED3 = 1;
		LED4 = 1; 
		LED5 = 1; 
		LED6 = 1; 
		LED7 = 1;

		for(timer = 0; timer < DELAY; timer++);

	}								
}

