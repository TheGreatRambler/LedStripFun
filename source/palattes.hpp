#include <cstdint>

#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {0xff0000, 0x00ff00, 0x0000ff};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);