#include<SDL2/SDL.h>
#include "globalvar.h"
#include "Button.h"

//Global Variables
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=580;

SDL_Window* window=NULL;
SDL_Surface* screenSurface = NULL; //rendering buffer

SDL_Surface* frbuffer = NULL; //temp buffer for dragging work
SDL_Surface* bkbuffer = NULL; //buffer for final drawing

const int BUT_NO=2; //Total no of buttons
Button butArray[BUT_NO]={
    Button(0,0,0), //button number x,y position (use loop for further buttons
    Button(1,100,0)
    };  // Objects for all the buttons

int FRAMERATE =35; //milliseconds to delay smaller is faster
//Eng of global variables


void updateDisplay() //this function will be called 1000/Framerate times in a second
{
    //merge all the buffers
    SDL_BlitSurface( bkbuffer, NULL, screenSurface, NULL );
    SDL_BlitSurface( frbuffer, NULL, screenSurface, NULL );
    SDL_UpdateWindowSurface( window );
}


int main(int c, char* argc[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) //init of sdl
    {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Paint", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 2;
    }
    screenSurface = SDL_GetWindowSurface( window ); //get the surface which will be displayed in monitor

    //create buffers
    frbuffer = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    bkbuffer = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT,32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    SDL_FillRect(bkbuffer, NULL, SDL_MapRGBA(bkbuffer->format, 0xFF, 0xFF, 0xFF,0xFF)); //white canvsa
    SDL_FillRect(frbuffer, NULL, SDL_MapRGBA(frbuffer->format, 0, 0, 0, 0)); //transparent canvas

    //load part
     //load image for buttons and assign functions
    butArray[0].display(); //draw buttons (use loop afterwards)
    butArray[1].display();
    //end of INIT


    //main loop
    bool quit = false;
    SDL_Event e;
    while( !quit )
    {
        SDL_Delay(FRAMERATE);
        quit = handleEvent( &e );
        updateDisplay();

    }
    //end main loop

    //house keeping for exit
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
