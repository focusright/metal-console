#include "pico/stdlib.h"

int main(void) {
    const uint signal_pin = 2;

    gpio_init(signal_pin);
    gpio_put(signal_pin, 0);
    gpio_set_dir(signal_pin, GPIO_OUT);

    while (true) {
        gpio_put(signal_pin, 1);
        sleep_ms(500);

        gpio_put(signal_pin, 0);
        sleep_ms(500);
    }
}