#include "mbed.h"
#include <cstdio>

/*
    This program follows the given flow chart
*/

InterruptIn blue_btn(PC_13);
DigitalOut led_A(LED1);
DigitalOut led_B(LED2);

volatile int flag;

void btnFall(){
    if (flag == 0) {
        flag = 1;
        led_A = !led_A;
        led_B= !led_B;
    }
    
}

void btnRise(){
    flag = 2;
}
int main()
{ 
    flag = 0;
    led_A = 1;
    led_B = 0;

    // blue_btn.fall(&btnFall);
    // blue_btn.rise(&btnRise);
    
    while(true){
        if(flag == 1){
            flag = 0;
            printf("Button pressed \r\n");
            // pressed = 1;
            // released = 0;
        } else if (flag == 2) {
            flag = 0;
            printf("Button released \r\n");
            // pressed = 0;
            // released = 1;
        }
    }

    return 0;
}
