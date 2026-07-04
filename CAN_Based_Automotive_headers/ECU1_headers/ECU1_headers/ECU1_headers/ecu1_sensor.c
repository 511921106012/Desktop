#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"

uint16_t get_speed( int speed ,char *str_s)
{
    // Implement the speed function

   /* reading 
    convertin 
    returning */


    str_s[0] = (speed /100) + 48;
    str_s[1] = (speed/10%10)+ 48;
    str_s[2] = (speed%10)+    48;
    str_s[3] = '/0';
    
}

unsigned char get_gear_pos()
{
    // Implement the gear function

   // reading dkp mood static_formet;

   static unsigned charter = 

}