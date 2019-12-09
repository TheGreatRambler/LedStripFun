#include <cstdint>

#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {0x800080, 0x86157f, 0x8c227e, 0x912d7c, 0x97377b,
                            0x9c4079, 0xa14878, 0xa65176, 0xab5975, 0xb06173,
                            0xb56971, 0xb9716f, 0xbe796d, 0xc2806b, 0xc68868,
                            0xcb9066, 0xcf9863, 0xd3a060, 0xd7a75d, 0xdbaf59,
                            0xdfb756, 0xe3bf52, 0xe6c74d, 0xeacf48, 0xeed742,
                            0xf1df3c, 0xf5e734, 0xf8ef2a, 0xfcf71c, 0xffff00};

const uint16_t palatteSize = sizeof(dotcolors) / sizeof(dotcolors[0]);