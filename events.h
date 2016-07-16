#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include "globalvar.h"


//class should be defined in header files
class Event
{
public:
    int buttonsel;
    int mousestate;
    int prevstate;
    int x;
    int y;
    int downx;
    int downy;
    int upx;
    int upy;
    int movex;
    int movey;
    int r,g,b,a;
    bool drag;
    /// can have states for brush size, selected color etc etc

    Event ()
    {
        buttonsel=-1;
        r= 0xFF;
        g= 0x00;
        b= 0x00;
        a= 0xFF;
        drag=false;
    }

    SDL_Rect normRect (int state) //return normalised rectangle from mouse clicks and drags
    {
        SDL_Rect pos;
        int ax,ay,bx=downx,by=downy;

        if (state == 1)
        {
            ax=upx;            ay=upy;
        }
        else
        {
            ax=x;            ay=y;
        }

        pos.x=(ax<bx)?ax:bx;
        pos.y=(ay<by)?ay:by;

        pos.w=(ax > bx)?(ax-bx):(bx-ax);
        pos.h=(ay > by)?(ay-by):(by-ay);
        return pos;

    }



    void display () //debugging info
    {
        std::cout
        <<"state:"<<mousestate<<" "
        <<buttonsel<<" "
        <<drag<<" "
        <<x<<" "
        <<y
        <<std::endl;
    }

};

#endif // EVENTS_H_INCLUDED
