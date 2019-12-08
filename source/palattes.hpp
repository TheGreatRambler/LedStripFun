#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {
    0x00ffff,  // lightblue
};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);

// Loop over the array to map the values correctly
// Simply bitshift to the right to make the W value zero
for (int i = 0; i < palatteSize; i++) {
    dotcolors[i] = dotcolors[i] >> 2;
}