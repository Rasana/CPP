#ifndef GLOBALVAR_H_INCLUDED
#define GLOBALVAR_H_INCLUDED


#include <SDL2/SDL.h>
#include<iostream>
//This is the file that will be shared across all the project
//declare (not define) global variables and functions here which will be used project wide

//Global Variables main.cpp
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;

extern SDL_Surface* frbuffer;
extern SDL_Surface* bkbuffer;

extern const int BUT_NO;
//Eng of global variables


//global functions
SDL_Surface* LoadImage(char* file); //loading.cpp
bool handleEvent( SDL_Event* e ); //events.cpp
void loadButtons(); //button.cpp

//end of global functions

#endif // GLOBALVAR_H_INCLUDED
