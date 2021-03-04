
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "e_init_port.h"
#include "e_motors.h"
#include "e_led.h"

void run_droit() {
  
    unsigned char a = 0;
float turnAngle = 0; 
  

    
    while(1) {
       
          
              switch(a) {
                case 0: 
                    e_set_speed_left(700);
                    e_set_speed_right(700);
                    e_set_steps_left(0);
					 e_led_clear();
                    a = 1;
                    break;
                case 1:
                    if(e_get_steps_left() >= 4500) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-300);
                    e_set_speed_right(300);
                  e_led_on();
                    turnAngle = 0;
                    a = 3;
                    break;
                case 3: 
                    turnAngle = e_get_steps_left();
                   
                    if(turnAngle <= -660) {   
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }
        }
    }


