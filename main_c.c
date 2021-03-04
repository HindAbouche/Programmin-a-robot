#include "p30f6014a.h"
#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "utility.h"
#include "e_ad_conv.h"
#include "e_led.h"
#include "e_prox.h"
#include "e_motors.h"
#include "rundetectsound.h"
#include "runsquare.h"
#include "droit.h"
#include "rungyroscope.h"
#include "runsquare2.h"
#include "demo0.h"
#include "demo1.h"
#include "demo2.h"
#include "escape.h"
#include "tera.h"
extern int selector;
#define DELAY	20000
int main(){
selector=getselector();
e_init_port();
e_init_ad_scan(ALL_ADC);
while(1){
if(selector==0){ 
demo0();		
}
else if(selector==1){
demo1();				
}
else if(selector==2){

demo2();
}else if(selector==3){
	run_droit();		
}else if(selector==4){
run_square();

}else if(selector==5){
run_spirale();
}else if(selector==6){
run_detectsound();
} else if(selector==7){
	while (1){
int timer;
	 if (e_get_prox(0)>300) {
         //	e_all_leds_on(1);
			e_set_speed_left(-400);
			e_set_speed_right(400);
	
    
}else 	if (e_get_prox(7)>300) {
         	//e_all_leds_on(1);
			e_set_speed_left(400);
			e_set_speed_right(-400);
		
}
 
						else
						{	e_set_speed_left(700);
							e_set_speed_right(700);
						//	e_all_leds_on(0);
						}		


	              
	

	}
}else if(selector==8){
escape();
}else if(selector==9){
Tera_term();
}else if(selector==10){
while (1) {

		// turn off all leds
		e_led_clear();
		e_set_body_led(0);
		e_set_front_led(0);
		
		// turn on leds based on proximity state
		if (e_get_prox(0)>400) 
			e_set_led(0,1);
		if (e_get_prox(1)>400) 
			e_set_led(1,1);
		if (e_get_prox(2)>400) 
			e_set_led(2,1);
		if (e_get_prox(3)>400) 
			e_set_led(3,1);
		if (e_get_prox(4)>400) 
			e_set_led(4,1);
		if (e_get_prox(5)>400) 
			e_set_led(5,1);
		if (e_get_prox(6)>400) 
			e_set_led(6,1);
		if (e_get_prox(7)>400) 
			e_set_led(7,1);

	}				
}else if(selector==11){

}else if(selector==12){

}else if(selector==13){

}else if(selector==14){
	
}else if(selector==15){

}else if(selector==16){
switch(selector) {
			case 0: e_set_led(0, 1);
					break;
			case 1: e_set_led(1, 1);
					break;
			case 2: e_set_led(2, 1);
					break;
			case 3: e_set_led(3, 1);
					break;
			case 4: e_set_led(4, 1);
					break;
			case 5: e_set_led(5, 1);
					break;
			case 6: e_set_led(6, 1);
					break;
			case 7: e_set_led(7, 1);
					break;
			case 8: e_set_body_led(1);
					break;
			case 9: e_set_front_led(1);
					break;
			default:e_set_led(8, 1); //turn on all leds
		}

}









}


}
