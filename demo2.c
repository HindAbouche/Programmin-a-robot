
#include "e_epuck_ports.h"
#include "e_init_port.h"

#define DELAY	8000

void demo2() {


	//T1CON = 0x8030; // Timer1 settings: TMR1 on, prescale 1:256
	TMR1 = 0;
	while (1) {
	    LED0 = 0;
	    LED1 = 0; 
		LED2 = 0; 
		LED3 = 0;
		LED4 = 0; 
		LED5 = 0; 
		LED6 = 0; 
		LED7 = 0;
while(TMR1 < DELAY);
		LED0 = 1; 
    
while(TMR1 < 15000);
		
	    LED1 = 1; 
	
while(TMR1 < 20000);
	
		LED2 = 1; 
	
while(TMR1 < 25000);
	
		LED3 = 1;
	
while(TMR1 < 30000);
	
		LED4 = 1; 
		
while(TMR1 <35000);
	
		LED5 = 1; 
	
while(TMR1 < 40000); 
	
		LED6 = 1; 
	
while(TMR1 < 45000);
	
		LED7 = 1;

	
	//	while(TMR1 < DELAY);

	}								
}
