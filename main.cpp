#include "mbed.h"

/*
    This program follows the given flow chart
*/

InterruptIn blue_btn(PC_13);    // initialise Digital in (InterruptIn)
DigitalOut led_A(LED1);         // initialise Digital Out 1
DigitalOut led_B(LED2);         // initialise Digital Out 2

volatile int flag;              // initialise flag

void btnFall(){                 // button pressed
    if (flag == 0) {            // checks if flag is 0
        flag = 1;               // if flag is 0, set flag = 1
        led_A = !led_A;         // toggle led_A
        led_B = !led_B;          // toggle led_B
    } 
}

void btnRise(){
    flag = 0;                   // button released, set flag = 0
}

int main()                      // start
{
    flag = 0;                   // set flag = 0
    led_A = 1;                  // set led_A on
    led_B = 0;                  // set led_B off

    blue_btn.fall(&btnFall);    // what happens when button is pressed
    blue_btn.rise(&btnRise);    // what happens when button is released

    while(true){}               // while(1)      
    
    return 0;
}
