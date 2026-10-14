#include "pico/stdlib.h"
#include <stdint.h>

void gp2_high(void);
void gp2_low(void);

int main(void) {
    const uint signal_pin = 2;
    const uint32_t signal_mask = 1u << signal_pin; //4, or binary 00000100. The bit position identifies the GPIO

    volatile uint32_t *const gpio_out_set = (volatile uint32_t *)0xD0000014u;
    volatile uint32_t *const gpio_out_clr = (volatile uint32_t *)0xD0000018u;
    volatile uint32_t *const gpio_oe_set = (volatile uint32_t *)0xD0000024u; //set the GPIO Output-Enable bits

    gpio_init(signal_pin);
    *gpio_out_clr = signal_mask;  // Prepare a LOW output value.
    *gpio_oe_set = signal_mask;   // Enable GP2's output driver.
    
    // while (true) {
    //     *gpio_out_set = signal_mask;
    //     sleep_ms(500);
    
    //     *gpio_out_clr = signal_mask;
    //     sleep_ms(500);
    // }

    while (true) {
        gp2_high();
        sleep_ms(500);
    
        gp2_low();
        sleep_ms(500);
    }
}