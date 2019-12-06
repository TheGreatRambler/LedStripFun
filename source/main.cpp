#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <stdarg.h>
#include <getopt.h>

extern "C" {
#include "rpi_ws281x/clk.h"
#include "rpi_ws281x/gpio.h"
#include "rpi_ws281x/dma.h"
#include "rpi_ws281x/pwm.h"
#include "rpi_ws281x/ws2811.h"
}

const int ledStringLength = 150;

uint32_t currentFrame = 0;

// Struct defining important stuff
ws2811_t ledstring = {
    .freq = WS2811_TARGET_FREQ,
    .dmanum = 10,
    .channel = {
        [0] = {
            .gpionum = 18,
            .invert = 0,
            .count = ledStringLength,
            .strip_type = WS2811_STRIP_GRB,
            .brightness = 255, // 0 to 255 brightness
        },
        [1] = {
            .gpionum = 0,
            .invert = 0,
            .count = 0,
            .brightness = 0,
        },
    },
};

void clearLedString() {
    for (int i = 0; i < ledStringLength; i++) {
        ledstring.channel[0].leds[i] = 0;
    }
}

void changeLedColors() {
    for (int i = 0; i < ledStringLength; i++) {
        // Just try light blue for now
        ledstring.channel[0].leds[i] = 0x00002020;
    }
}

static bool running = true;

static void ctrl_c_handler(int signum) {
	(void)(signum);
    running = false;
}

int main(int argc, char *argv[]) {
    ws2811_return_t ret;

    // Handle Ctrl C
    struct sigaction sa;
    sa.sa_handler = ctrl_c_handler,

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS) {
        fprintf(stderr, "ws2811_init failed: %s\n", ws2811_get_return_t_str(ret));
        return ret;
    }

    while (running) {
        changeLedColors();

        if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS) {
            fprintf(stderr, "ws2811_render failed: %s\n", ws2811_get_return_t_str(ret));
            break;
        }

        // 15 frames /sec
        currentFrame++;
        usleep(1000000 / 15);
    }

    clearLedString();
    ws2811_render(&ledstring);
    ws2811_fini(&ledstring);

    return ret;
}