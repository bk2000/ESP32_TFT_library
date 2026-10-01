/*
 * Simple LED blink example for ESP32.
 *
 * Toggles the GPIO selected in menuconfig ("LED Blink Configuration")
 * on and off every CONFIG_BLINK_PERIOD_MS milliseconds.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO       CONFIG_BLINK_GPIO
#define BLINK_PERIOD_MS  CONFIG_BLINK_PERIOD_MS

void app_main(void)
{
	gpio_config_t io_conf = {
		.pin_bit_mask = (1ULL << BLINK_GPIO),
		.mode = GPIO_MODE_OUTPUT,
		.pull_up_en = GPIO_PULLUP_DISABLE,
		.pull_down_en = GPIO_PULLDOWN_DISABLE,
		.intr_type = GPIO_INTR_DISABLE,
	};
	gpio_config(&io_conf);

	printf("Blinking LED on GPIO %d every %d ms\n", BLINK_GPIO, BLINK_PERIOD_MS);

	int level = 0;
	while (1) {
		level = !level;
		gpio_set_level(BLINK_GPIO, level);
		vTaskDelay(BLINK_PERIOD_MS / portTICK_PERIOD_MS);
	}
}
