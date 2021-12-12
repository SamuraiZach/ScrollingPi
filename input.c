#include "scroll.h"
#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
pi_joystick_t* js=NULL;

void openJoystick(void){ //allocate
        if(js==NULL){
                js=getJoystickDevice();
        }
}
void closeJoystick(void){ //de-allocate
        js=NULL;
}
void checkJoystick(void (*callback)(unsigned int code), int delay){
        pollJoystick(js,(*callback),delay);
}
