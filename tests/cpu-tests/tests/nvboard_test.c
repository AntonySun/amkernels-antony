#include <stdint.h>
#include "trap.h"
volatile uint16_t *aa = (volatile uint16_t *)(uintptr_t)(0x10002000);
int main() {
    uint16_t led = (uint16_t)0x0001 ;

    while(1) {
                if (led == 0) {
                    led = (uint16_t)0x0001;
                }
                *aa = (uint16_t)led;
                led = led << 1;
                printf("the led is 0x%04x\n",*(uint16_t *)(0x10002004));
        }

    return 0;
}