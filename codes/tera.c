#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_led.h"
#include "e_ad_conv.h"
#include "utility.h"
#include "memory.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "e_uart_char.h"
#include "e_motors.h"

#include <time.h>
extern int selector;
int i;
 char c;
char buffer[BUFFER_SIZE];

void Tera_term(){
static int value,id_led, speedr, speedl;
e_init_port();
e_init_uart1();
e_init_ad_scan(ALL_ADC);
selector=getselector();

sprintf(buffer, "Selector pos %d\r\n", selector);
	e_send_uart1_char(buffer, strlen(buffer));
	while(e_uart1_sending());
e_send_uart1_char("\f\a"
                "My Name is Hind Abouche\r\n"
                "this is my new programm\r\n"
               " taper\"H\" pour aide\r\n", strlen("\f\a"
                "My Name is Hind Abouche\r\n"
                "this is my new programm\r\n"
               " taper\"H\" pour aide\r\n"));
while(e_uart1_sending());


    while (1) {
       
           e_getchar_uart1(&c);


    
          
                while (c == '\n' || c == '\r') e_getchar_uart1(&c);
            
            buffer[0] = c;
            i = 1;
          
                do if (e_getchar_uart1(&c)) buffer[i++] = c;
                    while (c != '\n' && c != '\r');
            
            buffer[i++] = '\0';

            if ((buffer[0] != 'b') && (buffer[0] != 'g')) {
                buffer[0] = toupper(buffer[0]); // we also accept lowercase letters
            }
            switch (buffer[0]) {
  					case 'A': // set body led
                    //sscanf(buffer, "A,%d\r", &LED_action);
                  
                        e_led_on();
                      	e_send_uart1_char("tous les LEDs sont allumées\r\n", strlen("tous les LEDs sont allumées\r\n"));	while(e_uart1_sending());
                  
                    break;
            
                case 'B': // set body led
                    sscanf(buffer, "B,%d\r", &value);
                  
                        e_set_body_led(value);
if(value==1){
                      	e_send_uart1_char("la LED centrale est allumee\r\n", strlen("la LED centrale est allumee\r\n"));	while(e_uart1_sending());
}
else {	e_send_uart1_char("la LED centrale n'est pas allumee\r\n", strlen("la LED centrale n'est pas allumee\r\n"));	while(e_uart1_sending());
}
                  
                    break;
                case 'C': // read selector position
                    selector = SELECTOR0 + 2 * SELECTOR1 + 4 * SELECTOR2 + 8 * SELECTOR3;
                    sprintf(buffer, "le robot est dans la position :%d\r\n", selector);
                 e_send_uart1_char(buffer, strlen(buffer));	while(e_uart1_sending());
                 
                    break;
                case 'D': // set motor speed
                    sscanf(buffer, "D,%d,%d\r", &speedl, &speedr);
                    e_set_speed_left(speedl);
                    e_set_speed_right(speedr);
                        	e_send_uart1_char("le robot est en marche\r\n", strlen("le robot est en marche\r\n"));	while(e_uart1_sending());
                    
                    break;
            
                case 'F': // set front led
                    sscanf(buffer, "F,%d\r", &value);
    
                        e_set_front_led(value);
if(value==1){
                        e_send_uart1_char("la led frontale est allumée\r\n", strlen("la led frontale est allumée\r\n"));	while(e_uart1_sending());
}
else  { e_send_uart1_char("la led est frontale est non allumée\r\n", strlen("la led est frontale est non allumée\r\n"));	while(e_uart1_sending());}
                 
                    break;
 				case 'G': // set front led
                    sscanf(buffer, "G,%d,%d\r", &id_led,&value);
    
                        e_set_led(id_led,value);
							if(value==1)
                       { e_send_uart1_char("la led est allumée\r\n", strlen("la led est allumée\r\n"));	while(e_uart1_sending());}
						else 
                  { e_send_uart1_char("la led est éteint\r\n", strlen("la led est éteint\r\n"));	while(e_uart1_sending());}
                    break;

                case 'H': // ask for help
                    
                        e_send_uart1_char("\n", strlen("\n"));	while(e_uart1_sending());
     e_send_uart1_char("A--------************------- ALLUMER tout les LEDs\r\n", strlen("A--------************------- ALLUMER tout les LEDs\r\n"));	while(e_uart1_sending());          
 	 e_send_uart1_char("B,v------************------- LED CENTRALE: 0=OFF 1=ON \r\n", strlen("B,v------************------- LED CENTRALE: 0=OFF 1=ON \r\n"));	while(e_uart1_sending());
	 e_send_uart1_char("C--------************------- POSITION de Selecteur\r\n", strlen("C--------************------- POSITION de Selecteur\r\n"));	while(e_uart1_sending());
     e_send_uart1_char("D,vg,vl----************------- SET la vitesse des mouteurs gauche,droit\r\n", strlen("D,vg,vl----************------- SET la vitesse des mouteurs gauche,droit\r\n"));
  	while(e_uart1_sending()); 
     e_send_uart1_char("F,v------************------- Front led 0=OFF 1=ON \r\n", strlen("F,v------************------- Front led 0=OFF 1=ON \r\n"));	while(e_uart1_sending());
     e_send_uart1_char("G,id,v----************------- allumer uune seul led\r\n", strlen("G,id,v----************------- allumer uune seul led\r\n"));	while(e_uart1_sending());                  
     e_send_uart1_char("H--------************------- Help\r\n", strlen("H--------************------- Help\r\n"));	while(e_uart1_sending()); 
     e_send_uart1_char("E--------************------- la valeur de battry\r\n", strlen("E--------************------- la valeur de battry\r\n"));	while(e_uart1_sending());
     e_send_uart1_char("S--------************------- STOP e-puck and turn OFF LEDs\r\n", strlen("S--------************------- STOP e-puck and turn OFF LEDs\r\n"));	while(e_uart1_sending());
               
                    break;
               case 'E': 
                 // int k=;
    			sprintf(buffer, "pourcentage du charge :%d%%\r\n", getBatteryValuePercentage());
                 e_send_uart1_char(buffer, strlen(buffer));	while(e_uart1_sending());
                     
                    break;
                case 'S': // stop
                    e_set_speed_left(0);
                    e_set_speed_right(0);
                    e_set_led(8, 0);
                   e_set_front_led(0);
					e_set_body_led(0);
                      e_send_uart1_char("les LEDs et les mouteurs sont OFF\r\n", strlen("les LEDs et les mouteurs sont OFF\r\n"));	while(e_uart1_sending());
                   
                    break;
          

                default:
                 
                    //e_send_uart1_char("commande n'est pas trouvé\r\n", strlen("commande n'est pas trouvé\r\n"));	while(e_uart1_sending());
                    break;
            }
        
    }




}

