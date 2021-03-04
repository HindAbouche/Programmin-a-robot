
#include "e_epuck_ports.h"
#include "e_init_port.h"
#include "e_ad_conv.h"
#include "e_prox.h"
#include "e_motors.h"

#define DELAY 50000

void escape() {

	long timer = 0;

	

	while (1) {

		if (e_get_prox(0)>500) {		
			e_set_speed_left(-100);
			e_set_speed_right(-100);
		} else if (e_get_prox(0)>100) {	
			e_set_speed_left(100);
			e_set_speed_right(100);
		} else {						
			e_set_speed_left(0);
			e_set_speed_right(0);
		}

		for(timer = 0; timer < DELAY; timer++);

	}								
}
