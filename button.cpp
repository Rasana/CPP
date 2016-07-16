#include "globalvar.h"
#include "Button.h"

//declare functions from drawing.cpp
void drawRect(Event);
void drawLine(Event);

//load image and assign function to buttons use loop
void loadButtons()
{
    butArray[0].load("Pencil","res/line.bmp",drawLine);
    butArray[1].load("Pencil","res/rect.bmp",drawRect);
}









