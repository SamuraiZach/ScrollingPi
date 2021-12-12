#include "scroll.h"
#include "sense.h"
#include <stddef.h>
#include <stdio.h>

#define BLACK 0x0000
#define WHITE 0xFFFF

pi_framebuffer_t *fb=NULL;

void openDisplay(void){ //allocate global FB
        if(fb==NULL){
                fb=getFrameBuffer();
        }
}
void closeDisplay(void){ //de-allocate global FB
        if(fb){
                clearFrameBuffer(fb,BLACK);
                freeFrameBuffer(fb);
                fb=NULL;
        }
}
//offset is offset respect to corrd
int returnVariable(int Offset, int Position){
        int buffer = 0;
        if(Offset > Position){
                return Position;
        }else{
                return (Position - Offset);
        }
}
void displayLetter(char letter, int xOffset, int yOffset){
        sense_fb_bitmap_t *bm=fb->bitmap;
        clearFrameBuffer(fb,BLACK);
        if(letter == 'A'){ // DISPLAY Z

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,2)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,3)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,4)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,5)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,5)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,5)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,5)]=WHITE;

        }else if(letter == 'B'){ // DISPLAY B

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,2)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,3)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,3)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,4)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,4)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,4)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,5)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,5)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,6)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,6)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,6)]=WHITE;

        }else if(letter == 'C'){ // DISPLAY 3

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,2)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,2)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,3)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,4)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,4)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,4)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,2)][returnVariable(yOffset,5)]=WHITE;

                fb->bitmap->pixel[returnVariable(xOffset,3)][returnVariable(yOffset,6)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,4)][returnVariable(yOffset,6)]=WHITE;
                fb->bitmap->pixel[returnVariable(xOffset,5)][returnVariable(yOffset,6)]=WHITE;

        }
}
void clearDisplay(void){
        sense_fb_bitmap_t *bm=fb->bitmap;
        clearFrameBuffer(fb,BLACK);
        for(int i = 0; i < 8; i++){
                for(int k = 0; k < 8; k++){
                        fb->bitmap->pixel[i][k]=BLACK;
                }
        }
}
