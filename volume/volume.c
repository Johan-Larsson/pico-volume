#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"



int main()
{
    stdio_init_all();

    // Set up ADC
    adc_init();
    adc_gpio_init(27);
    adc_select_input(1);


    while (true) {
        uint16_t adc_value = adc_read();

        printf("Value: %d\n" , adc_value);
        
        uint16_t percentage = ((adc_value - 21) * (100 - 0) / (4095 - 21)) + 0;
        printf("percentage: %d\n" , percentage);
        sleep_ms(1000);
    }
}
