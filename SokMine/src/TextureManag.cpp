#include "TextureManag.h"




SDL_Texture* TextureManag::loadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}
void TextureManag::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}


TextureManag::TextureManag()
{
    //ctor
}

TextureManag::~TextureManag()
{
    //dtor
}
