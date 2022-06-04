#include "Game.h"
#include "TextureManag.h"
#include "GameObject.h"
#include "Map.h"
#include <stdio.h>

GameObject* player;
GameObject* box1;
GameObject* goal;
GameObject* boxOk;



Map* mape;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;



using namespace std;


Game::Game()
{

}

Game::~Game()
{
    //dtor
}
void Game::init(const char* title, int xpos,int ypos,
          int widhtpos,int heightpos, bool fullscreen){
              int flags = 0;
              if(fullscreen){
                flags =SDL_WINDOW_FULLSCREEN;

              }

                if(SDL_Init(SDL_INIT_EVERYTHING)==0){
                    cout<<"working"<<endl;
                    window = SDL_CreateWindow(title,  xpos, ypos,
           widhtpos, heightpos, flags);
           if(window){
                cout<<"window created"<<endl;
           }

           renderer = SDL_CreateRenderer(window,-1,0);
           if(renderer){
                SDL_SetRenderDrawColor(renderer,255,255,255,255);
                cout<<"renderer created"<<endl;
           }

           isRunning = true;
                } else {
                            isRunning = false;
                }

        player = new GameObject("images/boy.png",232,232);
        box1 = new GameObject("images/box.png",264,360);
        goal = new GameObject("images/goal.png",264,232);
        boxOk = new GameObject("images/boxOk.png",264,232);
        mape = new Map();






          }



void Game::handleEvents(){
    int Posx = player->getPosX();
    int Posx2 = goal->getPosX();
    int Posx1 = box1->getPosX() ;
    int Posy  = player->getY()  ;
    int Posy2  = goal->getY()  ;
    int Posy1 = box1->getY()  ;

    while (SDL_PollEvent(&event)){

if((Posx1 == Posx2) && (Posy1 == Posy2))
                    {
                        box1 = boxOk;
                    }
                    if((!Posx2) && (!Posy2))
                        {box1 = box1;}
    if(event.type == SDL_QUIT){
        isRunning=false;
    }
    if(event.type == SDL_KEYDOWN){

        switch (event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    // Move the player to the right.
                    player->setX(32, mape);
                        // If the player happens to be f
                        // -acing a box, attempt to move
                        // it.
                    if ((Posx + 32 == Posx1) && (Posy == Posy1))
                    {
                            // We can't move the box, rev
                            // -ert back to the original
                            // position.
                                if (! box1->setX(32, mape))
                                                player->setX(-32, mape);
                            //
                    }




                    break;
                case SDLK_UP:
                    // Move the player to the right.
                    player->setY(-32, mape);
                        // If the player happens to be f
                        // -acing a box, attempt to move
                        // it.
                    if ((Posx  == Posx1) && (Posy - 32 == Posy1))
                    {
                            // We can't move the box, rev
                            // -ert back to the original
                            // position.
                                if (! box1->setY(-32, mape))
                                                player->setY(32, mape);
                            //
                    }


                    break;


                case SDLK_DOWN:
                    // Move the player to the right.
                    player->setY(32, mape);
                        // If the player happens to be f
                        // -acing a box, attempt to move
                        // it.
                    if ((Posx == Posx1) && (Posy + 32 == Posy1))
                    {
                            // We can't move the box, rev
                            // -ert back to the original
                            // position.
                                if (! box1->setY(32, mape))
                                                player->setY(-32, mape);
                            //
                    }



                    break;
                case SDLK_LEFT:
                    // Move the player to the right.
                    player->setX(-32, mape);
                        // If the player happens to be f
                        // -acing a box, attempt to move
                        // it.
                    if ((Posx - 32 == Posx1) && (Posy == Posy1))
                    {
                            // We can't move the box, rev
                            // -ert back to the original
                            // position.
                                if (! box1->setX(-32, mape))
                                                player->setX(32, mape);
                            //
                    }


                    break;

                default:
                    break;
            }

        }
   }
   //if(player->getPos()+1 == box1->getX() || player->getY()+1 == box1->getY() )
   //{
  //     cout<<"box ";
  //     box1->setX(32,mape);
   //}
}





void Game::update(){

  player->Update();
  box1->Update();
  goal->Update();

}
void Game::render(){

    SDL_RenderClear(renderer);
    mape->DrawMap();
    //add stuff to render
    goal->Render();
    box1->Render();
    player->Render();

    SDL_RenderPresent(renderer);

}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
        cout<<" Cleaned Successfully ;) "<<endl;

}
