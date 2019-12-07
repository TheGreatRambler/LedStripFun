#include <rpi_ws281x/clk.h>
#include <rpi_ws281x/gpio.h>
#include <rpi_ws281x/dma.h>
#include <rpi_ws281x/pwm.h>
#include <rpi_ws281x/ws2811.h>

// Check https://gka.github.io/palettes
ws2811_led_t dotcolors[] = {
    0x00c07100,
    0x00c07012,
    0x00c06f1e,
    0x00c06d27,
    0x00c06c2f,
    0x00c06b36,
    0x00c06a3d,
    0x00c06843,
    0x00c0674a,
    0x00bf6650,
    0x00bf6556,
    0x00be645c,
    0x00be6261,
    0x00bd6167,
    0x00bd606d,
    0x00bc5f73,
    0x00bb5e79,
    0x00ba5c7e,
    0x00b95b84,
    0x00b85a8a,
    0x00b65990,
    0x00b55895,
    0x00b3579b,
    0x00b256a1,
    0x00b054a6,
    0x00ae53ac,
    0x00ac52b2,
    0x00a951b8,
    0x00a750be,
    0x00a44fc4,
    0x00a14ec9,
    0x009e4dcf,
    0x009b4dd5,
    0x00974cdb,
    0x00934be1,
    0x008f4ae7,
    0x008a49ed,
    0x008549f3,
    0x007f48f9,
    0x007947ff
};
