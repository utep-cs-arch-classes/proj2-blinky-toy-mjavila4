#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char redOn = 0;        //Keeps track of light toggle within binary count
static char greenOn = 0;
static char stateCycle = 0;   /*Allows dimState() to increase brightness after
                              every finished binary count*/

char redToggle(){             //Toggle red light
  static char state = 0;
  if(state == 0){
    red_on = 1;
    state = 1;
    redOn = 1;
  }else{
    red_on = 0;
    state = 0;
    redOn = 0;
  }
  return 1;
}

char greenToggle(){          //Toggle green light 
  static char state = 0;
  if(state == 0){
    green_on = 1;
    state = 1;
    greenOn = 1;
  }else{
    green_on = 0;
    state = 0;
    greenOn = 0;
  }
  return 1;
}

void state_advance(){       //2-bit binary count
  static char state = 1;
  static char counter = 0;

  redToggle();              //Always toggle red in each count state
  
  switch(state){            //Toggles green every two state transitions
    case 0:
      greenToggle();
      state = 1;
      break;
    case 1:
      state = 0;
      break;
  }
  
  if(counter++ == 3){       //Increment stateCycle after one full binary count
    counter = 0;
    if(stateCycle++ == 3){
      stateCycle = 0;
    }
  }
  
  led_changed = 1;
  led_update();

} 

void dimState(){            //Brightens leds after every binary count
  static char state = 0;  
  switch(stateCycle){
    case 0:                 //%25 led brightness
      if(state++ == 3){  
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
        state = 0;
      }else{
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
      }
      break;
    case 1:                 //%50 led brightness
      if(state++ == 1){  
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
        state = 0;
      }else{
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
      }
      break;
  case 2:                    //%75 led brightness
      if(state++ == 3){  
        if(redOn){red_on = 0;}
        if(greenOn){green_on = 0;}
        state = 0;
      }else{
        if(redOn){red_on = 1;}
        if(greenOn){green_on = 1;}
      }
      break;
  }
  
  led_changed = 1;
  led_update();

}
