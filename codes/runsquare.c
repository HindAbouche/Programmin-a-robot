#include "p30F6014A.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_led.h"

void run_square() {
  
     char a = 0;
float Angle ; 
  

    
    while(1) {
       
          
              switch(a) {
                case 0: 
                    e_set_speed_left(300);
                    e_set_speed_right(300);
                    e_set_steps_left(0);
					e_set_body_led(0);
					e_set_front_led(0);
                    a = 1;
                    break;
                case 1: 
                    if(e_get_steps_left() >= 800) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-100);
                    e_set_speed_right(100);
					e_set_body_led(1);
						e_set_front_led(1);
                   Angle = 0;
                    a = 3;
                    break;
                case 3: 
                   Angle = e_get_steps_left();
                    
                    
                    if(Angle <= -330) {    
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }
        }
    }


