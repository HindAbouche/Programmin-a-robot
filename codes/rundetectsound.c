
#include "e_micro.h"
#include "e_motors.h"
#include "utility.h"

#define VOLUME 100

void run_detectsound() {
    int vol0=0, vol1=0, vol2=0;
    int maxVol;
     char micId=0;


    while(1) {
        vol0 = e_get_micro_volume(0);
        vol1 = e_get_micro_volume(1);
        vol2 = e_get_micro_volume(2);
        maxVol = vol0;
        micId = 0;
        if(vol1 > maxVol) {
            maxVol = vol1;
            micId = 1;
        }
        if(vol2 > maxVol) {
            maxVol = vol2;
            micId = 2;
        }
       e_set_speed_right(0);
	e_set_speed_left(0);
        if(maxVol > VOLUME) {
            switch(micId) {
                case 0: e_set_speed_right(-900);
						e_set_speed_left(900);
                        resetTime();
                        while(getDiffTimeMs() < 1000);
                        break;
                case 1: e_set_speed_right(900);
						e_set_speed_left(-900);
                        resetTime();
                        while(getDiffTimeMs() < 1000);
                        break;
                case 2: e_set_speed_right(900);
						e_set_speed_left(900);
                        resetTime();
                        while(getDiffTimeMs() < 1000);
                        break;
            }
        }
    }

}
