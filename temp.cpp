#include "globalvar.h"
#include "Button.h"

//Global Variables
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;

SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;

const int BUT_NO=1; //Total no of buttons
Button butArray[BUT_NO];  // Objects for all the buttons

int FRAMERATE =10; //smaller is faster
//Eng of global variables


void updateDisplay()
{
    //SDL_RenderClear(renderer);
    butArray[0].display();
    SDL_RenderPresent(renderer);
}

//int main(int c, char* argc[])
//{
//    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
//    {
//        std::cout << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    window = SDL_CreateWindow("Lesson 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if (window == NULL)
//    {
//        std::cout << SDL_GetError() << std::endl;
//        return 2;
//    }
//
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//    if (renderer == NULL)
//    {
//        std::cout << SDL_GetError() << std::endl;
//        return 3;
//    }
//
//    //load part
//    loadButtons();
//    //end of loading
//
//
//    //init
//    SDL_SetRenderDrawColor( renderer, 0x66, 0x66, 0x66, 0xFF );
//    SDL_RenderClear(renderer);
//    butArray[0].display();
//    SDL_RenderPresent(renderer);
//    //end of INIT
//
//
//
//    //main loop
//    bool quit = false;
//    SDL_Event e;
//    while( !quit )
//    {
//        SDL_Delay(FRAMERATE);
//        quit = handleEvent( &e );
//        updateDisplay();
//    }
//    //end main loop
//
//    //house keeping for exit
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//
//    SDL_Quit();
//
//    return 0;
//}
