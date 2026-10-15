#include "pico/stdlib.h"

void gp2_high(void);
void gp2_low(void);
void gp2_init_low(void);
void gp2_enable_output(void);
void gp2_select_sio(void);

int main(void) {
    gp2_select_sio();
    gp2_init_low();          // Initialize output value to LOW
    gp2_enable_output();     // Enable GP2 output driver
    
    while (true) {
        gp2_high();
        sleep_ms(500);
    
        gp2_low();
        sleep_ms(500);
    }
}