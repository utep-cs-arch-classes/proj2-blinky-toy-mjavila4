#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)

void switchInit();
void switchInterruptHandler();

extern char switch1StateDown, switch2StateDown, switch3StateDown, switch4StateDown;
extern char switchStateChanged;

#endif
