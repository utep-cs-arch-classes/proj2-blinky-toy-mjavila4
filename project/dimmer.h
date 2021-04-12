#ifndef _DIMMER_
#define _DIMMER_

extern unsigned char dimRed, dimGreen, dimPer, maxCount, highOut, lowOut;

void stateDim();
void dimInit();
void redBlink();
void greenBlink();

#endif
