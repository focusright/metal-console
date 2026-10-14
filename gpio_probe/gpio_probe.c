#include "pico/stdlib.h"
#include <stdint.h>

int main(void) {
    const uint signal_pin = 2;
    const uint32_t signal_mask = 1u << signal_pin;

    volatile uint32_t *const gpio_out_set = (volatile uint32_t *)0xD0000014u;
    volatile uint32_t *const gpio_out_clr = (volatile uint32_t *)0xD0000018u;

    gpio_init(signal_pin);
    gpio_put(signal_pin, 0);
    gpio_set_dir(signal_pin, GPIO_OUT);

    while (true) {
        *gpio_out_set = signal_mask;
        sleep_ms(500);
    
        *gpio_out_clr = signal_mask;
        sleep_ms(500);
    }
}