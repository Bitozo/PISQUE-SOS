#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 2 // Pino do LED 

void blink_led(int times, int delay_ms) {
    for (int i = 0; i < times; i++) {
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}

void app_main(void) {
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // S (3 piscadas curtas)
        blink_led(3, 200);
        vTaskDelay(pdMS_TO_TICKS(600));
        
        // O (3 piscadas longas)
        blink_led(3, 600);
        vTaskDelay(pdMS_TO_TICKS(600));
        
        // S (3 piscadas curtas)
        blink_led(3, 200);
        vTaskDelay(pdMS_TO_TICKS(2000)); // Pausa entre repetições
    }
}
