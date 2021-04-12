#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "dimmer.h"
#include "buzzer.h"

void main(void){

  configureClocks();
  switchInit();
  ledInit();
  buzzer_init();
  
  enableWDTInterrupts();

  or_sr(0x18);

}
