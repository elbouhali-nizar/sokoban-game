#ifndef TEXTUREMANAG_H
#define TEXTUREMANAG_H
#pragma once
#include "Game.h"
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
/*! \class TextureManag
  \brief classe de la texture


      cette class sert a telecharger le fichier(image) et la manipuler
    */
class TextureManag
{
    public:
        /*! \fn loadTexture
            \brief pour telecharger le fichier
            @param filename le lien du fichier

      */
        static SDL_Texture* loadTexture(const char* filename);
         /*! \fn loadTexture
            \brief pour dessiner le fichier
            @param tex la texture
            @param src les references du fichier
            @param dest les references du fichier

      */
        static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
        /*! \fn TextureManag
       \brief un constructeur

      Le constructeur est la fonction membre appelee automatiquement lors de la creation d'un objet (en statique ou en dynamique).
       Cette fonction membre est la premiere fonction membre a etre executee, il s'agit donc d'une fonction permettant l'initialisation des variables.
    */
        TextureManag();
        /*! \fn ~TextureManag
       \brief un destructeur

      Le destructeurs sont en quelque sorte au constructeur ce que la mort est a la vie,
       c'est-a-dire qu'il s'agit d'une fonction membre qui intervient automatiquement lors de la destruction d'un objet.
    */
        virtual ~TextureManag();

    protected:

    private:
};

#endif // TEXTUREMANAG_H
