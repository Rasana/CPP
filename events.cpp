#include "globalvar.h"
#include "Button.h"
#include "events.h"

Event event; //global event and state.. can be extended for overall program state

//defined below
void mouseup(int x, int y);
void mousemove(int x, int y);
void mousedown(int x, int y);

int x; //for polling mouse state from SDL
int y;
bool handleEvent( SDL_Event* e )
{
    while( SDL_PollEvent( e ) != 0 )
        {
            SDL_GetMouseState( &x, &y );
            event.x=x;
            event.y=y;
            if( e->type == SDL_QUIT )
            {
                return true;
            }
            else if( e->type == SDL_MOUSEBUTTONDOWN )
            {
                if (event.drag == false) //dont update mouse down for drag
                {
                    event.downx=x;
                    event.downy=y;
                }
                event.drag=true;

                event.prevstate=event.mousestate;
                event.mousestate=1;
                mousedown(x,y);
            }
            else if( e->type == SDL_MOUSEBUTTONUP )
            {
                event.upx=x;
                event.upy=y;
                event.prevstate=event.mousestate;
                event.mousestate=3;
                event.drag=false;
                mouseup(x,y);
            }
            else if( e->type == SDL_MOUSEMOTION  )
            {
                event.movex=x;
                event.movey=y;
                event.prevstate=event.mousestate;
                event.mousestate=2;
                mousemove(x,y);
            }


        }
        return false;
}


void mousedown(int x, int y)
    {
//        if (event.buttonsel != -1)
//        {
//            //
//        }
        event.display();

    }

 void mouseup(int x, int y)
    {
        //check if button was pressed and assign selected button
        if (butArray[0].isPressed (x,y) == true)
        {
            event.buttonsel=0;
        }
        else if (butArray[1].isPressed (x,y) == true)
        {
            event.buttonsel=1;
        }
        else if (event.buttonsel>=0) //or do the action for current selected button
        {
            butArray[event.buttonsel].func(event);
        }

        event.display();
    }


void mousemove(int x, int y)
    {
        if (event.drag == true)
        {
            if (event.buttonsel != -1)
            {
                butArray[event.buttonsel].func(event);
            }
            event.display();
        }

    }


