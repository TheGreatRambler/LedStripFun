#include <cstdint>

#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {0xff972c, 0xff942c, 0xff912d, 0xff8e2d, 0xff8b2d,
                            0xff882e, 0xff852e, 0xff822f, 0xff7e2f, 0xff7b30,
                            0xff7830, 0xff7430, 0xff7131, 0xff6d31, 0xff6931,
                            0xff6531, 0xff6232, 0xff5e32, 0xff5932, 0xff5533,
                            0xff5033, 0xff4b33, 0xff4633, 0xff4133, 0xff3b34,
                            0xff3434, 0xff2c34, 0xff2334, 0xff1634, 0xff0034};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);