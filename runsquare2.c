
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "e_init_port.h"
#include "e_motors.h"
//#include "square.h"
#include "e_led.h"
void run_spirale() {
  
    unsigned char a = 0;
float turnAngle = 0; 
  
int n=0;
    
    while(n<=3) {
       
          
              switch(a) {
                case 0: 
                    e_set_speed_left(600);
                    e_set_speed_right(600);
                    e_set_steps_left(0);
                    n++;
                    a = 1;
                    break;
                case 1: 
                    if(e_get_steps_left() >= 3000) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-400);
                    e_set_speed_right(400);
                    turnAngle = 0;
                    a = 3;
                    break;
                case 3: 
                    turnAngle = e_get_steps_left();
                    
                    if(turnAngle <= -320) {    
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }

        }
e_set_front_led( 1);
n=0;
  while(n<2) {
       
          e_set_front_led(0);
              switch(a) {
                case 0: 
                    e_set_speed_left(600);
                    e_set_speed_right(600);
                    e_set_steps_left(0);
                    n++;
                    a = 1;
                    break;
                case 1: 
                    if(e_get_steps_left() >= 2500) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-400);
                    e_set_speed_right(400);
                    turnAngle = 0;
                    a = 3;
                    break;
                case 3: 
                    turnAngle = e_get_steps_left();
                    
                    if(turnAngle <= -320) {    
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }

        }
e_set_front_led( 1);
n=0;
  while(n<2) {
       
          e_set_front_led( 0);
              switch(a) {
                case 0: 
                    e_set_speed_left(600);
                    e_set_speed_right(600);
                    e_set_steps_left(0);
                  n++;
                    a = 1;
                    break;
                case 1: 
                    if(e_get_steps_left() >= 1700) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-400);
                    e_set_speed_right(400);
                    turnAngle = 0;
                    a = 3;
                    break;
                case 3: 
                    turnAngle = e_get_steps_left();
                    
                    if(turnAngle <= -320) {    
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }

        }

n=0;
e_set_front_led( 1);

  while(n<3) {
       e_set_front_led( 0);
          
              switch(a) {
                case 0: 
                    e_set_speed_left(600);
                    e_set_speed_right(600);
                    e_set_steps_left(0);
                  n++;
                    a = 1;
                    break;
                case 1: 
                    if(e_get_steps_left() >= 1000) {
                        a = 2;
                    }
                    break;
                case 2: 
                    e_set_steps_left(0);
                    e_set_speed_left(-400);
                    e_set_speed_right(400);
                    turnAngle = 0;
                    a = 3;
                    break;
                case 3: 
                    turnAngle = e_get_steps_left();
                    
                    if(turnAngle <= -320) {    
                        e_set_speed_left(0);
                        e_set_speed_right(0);
                        a = 0;
                    }
                    break;
            }


        }

             

    }


