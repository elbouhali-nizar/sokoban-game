#include "GameObject.h"
#include "TextureManag.h"
#include "Map.h"

GameObject::GameObject(const char* texturesheet,int x,int y)
{
    objTexture = TextureManag::loadTexture(texturesheet);

    xpos = x;
    ypos = y;
}

GameObject::~GameObject()
{

}
bool GameObject::setY(int y,Map* map)
{
     int tx, ty;
tx = xpos / 32;
ty = (ypos / 32);
int* m = map->getMap();
if (m[(ty+(y < 0 ? -1 : 1)) * 25 + tx] != 2)
     return false;
     ypos += y;
     return true;
}

bool GameObject::setX(int x,Map* map)
{
    int tx, ty;
tx = xpos / 32;
ty = (ypos / 32);
int* m = map->getMap();
if (m[ty * 25 + (tx + (x < 0 ? -1 : 1))] != 2  )
     return false;
     xpos += x;
     return true;
}
int GameObject::getPosX()
{
    return xpos;
}
int GameObject::getY()
{
    return ypos;
}


void GameObject::Update()
{
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w  ;
    destRect.h = srcRect.h  ;
}
void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objTexture, &srcRect,&destRect);
}
