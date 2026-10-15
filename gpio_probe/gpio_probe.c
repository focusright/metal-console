#include "pico/stdlib.h"
#include <stdint.h>

void gp2_high(void);
void gp2_low(void);
void gp2_init_low(void);
void gp2_enable_output(void);

int main(void) {
    const uint signal_pin = 2;
    const uint32_t signal_mask = 1u << signal_pin; //4, or binary 00000100. The bit position identifies the GPIO

    gpio_init(signal_pin);   // Configure GP2 for SIO
    gp2_init_low();          // Initialize output value to LOW
    gp2_enable_output();     // Enable GP2 output driver
    
    while (true) {
        gp2_high();
        sleep_ms(500);
    
        gp2_low();
        sleep_ms(500);
    }
}