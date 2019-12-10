#include <cstdint>

#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {0xff0000, 0xf52700, 0xec3800, 0xe24400, 0xd84d00,
                            0xce5500, 0xc45b00, 0xba6100, 0xb06500, 0xa66a00,
                            0x9b6d00, 0x917100, 0x867400, 0x7a7600, 0x6e7800,
                            0x617a00, 0x537c00, 0x437e00, 0x2d7f00, 0x008000};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);