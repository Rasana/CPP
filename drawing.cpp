#include "events.h"
#include "math.h"


//used for plotting single pixel in x,y of surface with color
void PutPixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    *((Uint32*)pixel) = color;
}

unsigned int GetPixel(SDL_Surface *surface, int x, int y)
{
    Uint8 * pixel = (Uint8*)surface->pixels;
    pixel += (y * surface->pitch) + (x * sizeof(Uint32));
    return *((Uint32*)pixel);
}

void drawRect(Event event)
{
    SDL_Rect pos;
    if (event.drag == false) //final mouseup state
    {
        pos=event.normRect(1); //get the rectangle for drawing
        SDL_FillRect(frbuffer, NULL , SDL_MapRGBA(frbuffer->format, 0x00, 0x00, 0x00,0x00)); //clear front buffer
        SDL_FillRect(bkbuffer, &pos , SDL_MapRGBA(bkbuffer->format, 0xFF, 0x00, 0x00,0xFF)); //draw in permanent buffer (red)
    }
    else //dragging state
    {
        pos=event.normRect(2);
        SDL_FillRect(frbuffer, NULL , SDL_MapRGBA(frbuffer->format, 0x00, 0x00, 0x00,0x00)); //clear front buffer
        SDL_FillRect(frbuffer, &pos , SDL_MapRGBA(frbuffer->format, 0x00, 0xFF, 0x00,0xFF)); //animate the temp buffer (green)
    }

}


//uses line drawing algorithm to plot each pixel
void plotLine(SDL_Surface *Screen, int x0, int y0, int x1, int y1, Uint32 pixel)
{
    int i;
    double x = x1 - x0;
    double y = y1 - y0;
    double length = sqrt( x*x + y*y );
    double addx = x / length;
    double addy = y / length;
    x = x0;
    y = y0;

    for ( i = 0; i < length; i += 1) {
        PutPixel(Screen, x, y, pixel );
        x += addx;
        y += addy;

    }
}

void drawLine(Event event)
{
    SDL_Rect pos;
    if (event.drag == false)
    {
        pos=event.normRect(1); //final draw
        SDL_FillRect(frbuffer, NULL , SDL_MapRGBA(bkbuffer->format, 0x00, 0x00, 0x00,0x00)); //clear front buffer
        SDL_LockSurface(bkbuffer); //make surface pixel addressable
        plotLine(bkbuffer,event.downx,event.downy,event.upx,event.upy,SDL_MapRGBA(frbuffer->format, 0x00, 0x00, 0x00,0xFF));
        SDL_UnlockSurface(bkbuffer);
    }
    else
    {
        pos=event.normRect(2); //drag draw
        SDL_FillRect(frbuffer, NULL , SDL_MapRGBA(bkbuffer->format, 0x00, 0x00, 0x00,0x00)); //clear front buffer
        SDL_LockSurface(frbuffer);
        plotLine(frbuffer,event.downx,event.downy,event.x,event.y,SDL_MapRGBA(frbuffer->format, 0x00, 0x00, 0x00,0xFF));
        SDL_UnlockSurface(frbuffer);
    }


}

void drawPencil()
{
    //make small 3x3 pixels rectangles continiously as 1 pixel cannot be seen
}

void drawBrush()
{
    //same as pencil but bigger circles.
}

void eraser ()
{
    //same as brush but white color
}

void fill()
{
    //you have to read the filling algorithm and implement by the get and set pixel methods
}
