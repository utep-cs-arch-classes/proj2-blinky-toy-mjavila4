#ifndef led_included
#define led_included

#define LED_GREEN BIT0
#define LED_RED BIT6
#define LEDS (BIT0 | BIT6)

#include <msp430.h>

extern unsigned char redOn, greenOn, ledChanged;

void ledInit();
void ledUpdate();

#endif
