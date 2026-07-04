#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "uart.h"


void iit_config()

{
    init_adc();
    init_dkp ();
    init_uart();

}

int main()
{

    int config();
    while(1){

    

    unsigned int speed = get_speed();
     unsigned char gear =  get_gera_pos(); // based on the swtch press increse gear ;


    }

   // printf it ising uart 

   char str_s[4];
   // do not want exact printing ;
   my_itoa(sppd,str_s); // only we printing 3 digit only  max 3 digit only ;

   puts("speed : "); // convert integer to string i to a function 

   put(str_s); // printing 

   put(" Gear : ");

   putch(gear);

   puts("\n\r");


    //Call the functions
}