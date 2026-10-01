### LED blink example

A minimal ESP32 example that blinks an LED. It is a standalone esp-idf project and does not use the TFT library.

#### Wiring

Connect an LED (with a ~330 Ω series resistor) between the configured GPIO and GND. Many ESP32 dev boards already have an LED on **GPIO 2**, which is the default.

#### Configure, build and flash

From this directory (`examples/led_blink`):

Legacy make build:

```
make menuconfig    # "LED Blink Configuration" -> GPIO and blink period
make flash monitor
```

CMake build (esp-idf v4 and later):

```
idf.py menuconfig
idf.py flash monitor
```
