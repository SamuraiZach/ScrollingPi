#include "sense.h"
#include <stdio.h>
#include "scroll.h"
#include <linux/input.h>

int running=1;
int xPos=7; // Far right
int yPos=7; // Top
//Starting (X,Y) = (0,0)
char displayL='A';
int delay = 1000;
void handler(unsigned int code);

int main(void){
        openJoystick();
        openDisplay();
        while(running){
                int lastX =-1,lastY=-1;
                checkJoystick(handler,delay);
                if(lastX!=xPos || lastY!=yPos){
                        lastX = xPos;
                        lastY = yPos;
                        displayLetter(displayL,xPos,yPos);
                        //printf("%d",xPos);
                        //printf(" + %d",yPos);
                }
        }
        closeDisplay();
        closeJoystick();
}
void handler(unsigned int code){
        if(code == KEY_RIGHT){
                if(yPos == 0){
                        yPos = 7;
                }else{
                        yPos--;
                }
        }
        else if(code == KEY_LEFT){
                if(yPos == 7){
                        yPos = 0;
                }else{
                        yPos++;
                }
        }
        else if(code == KEY_DOWN){
                if(xPos == 0){
                        xPos = 7;
                }else{
                        xPos--;
                }
        }
        else if(code == KEY_UP){
                if(xPos == 7){
                        xPos = 0;
                }else{
                        xPos++;
                }
        }
        else if(code == KEY_ENTER){
                if(displayL == 'A'){
                        displayL = 'B';
                }else if(displayL == 'B'){
                        running = 0;
                }
        }
}
