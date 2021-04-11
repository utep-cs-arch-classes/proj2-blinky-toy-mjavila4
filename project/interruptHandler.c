#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

/*void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blinkCount = 0;

  if(++blinkCount == 125){

    //stateAdvance();
    blinkCount = 0;

  }

  }*/

void __interrupt_vec(PORT2_VECTOR) Port_2(){

  if(P2IFG & SWITCHES){

    P2IFG &= ~SWITCHES;
    switchInterruptHandler();
    
  }

}
