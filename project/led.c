#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char redOn = 0, greenOn = 0;
unsigned char ledChanged = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void ledInit(){

  P1DIR |= LEDS;
  ledChanged = 1;
  ledUpdate();

}

void ledUpdate(){

  if(ledChanged){

    char ledFlags = redVal[redOn] | greenVal[greenOn];

    P1OUT &= (0xff^LEDS) | ledFlags;
    P1OUT |= ledFlags;
    ledChanged = 0;

  }

}
