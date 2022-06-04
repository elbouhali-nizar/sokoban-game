#include <exception>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include "TextureManag.h"
#include "GameObject.h"







Game *game = nullptr;


int main( int argc, char * argv[] )
{



    game = new Game();


game->init("Sokoban" ,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);
while (game->running()){



    game->handleEvents();
    game->update();
    game->render();


   //frameTime = SDL_GetTicks() - frameStart;

   // if(frameDelay>frameTime){
    //    SDL_Delay(frameDelay - frameTime);

    //}



}
    game->clean();

    return 0;
}
