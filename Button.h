#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "globalvar.h"
#include "events.h"


//class should be defined in header files
class Button
{
    public:
    int butno; //identifier of button
    char* name;
    SDL_Surface* bimage;
    SDL_Rect pos;
    void (*func)(Event); //call back function for button ( pointer to function)

    Button(int butn,int ix =0, int iy =0)
    {
        butno=butn;
        pos.x=ix;
        pos.y=iy;
    }
    void display()
    {
        SDL_BlitSurface( bimage, NULL, bkbuffer, &pos );
    }
    void load(char* name,char* path, void (*funci)(Event))
    {
        name = name;
        bimage= LoadImage(path);
        pos.w =50;//bimage->w;
        pos.h =50;//bimage->h;
        func= funci;
    }
    ~Button()
    {
        SDL_FreeSurface( bimage );
    }
    bool isPressed(int x,int y) //returns true if x,y lies over the button
    {
         if ((x>pos.x) && (x<(pos.w+pos.x)) && (y>pos.y) && (y<(pos.h+pos.y)))
         {
             return true;
         }
         return false;
    }

};

extern Button butArray[]; //make button global

#endif // BUTTON_H_INCLUDED
