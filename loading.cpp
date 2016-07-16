#include "globalvar.h"

//file for loading stuffs


//image loading function
SDL_Surface* LoadImage(char* file)
{
    SDL_Surface* image=NULL;

    image=SDL_LoadBMP(file);
    image = SDL_ConvertSurface( image, screenSurface->format, NULL ); //convert to blitting freindly format

    return image;
}
