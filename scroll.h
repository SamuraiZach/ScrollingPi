#include "sense.h"
#include <stdlib.h>
#include <stdio.h>

void openJoystick(void);
void closeJoystick(void);
void checkJoystick(void (*callback)(unsigned int),int);
void openDisplay(void);
void closeDisplay(void);
void displayLetter(char,int,int);
void clearDisplay(void);
