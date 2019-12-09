#include <cstdint>

#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {0xff0000, 0xd15300, 0xa16c00, 0x6b7900, 0x008000};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);