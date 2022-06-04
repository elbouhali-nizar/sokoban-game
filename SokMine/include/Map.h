#ifndef MAP_H
#define MAP_H
#pragma once
#include "Game.h"

/*! \class Map
    \brief classe de la carte



      cette class sert a la modification et la manipulation de la carte
    */
class Map
{
    public:
        /*! \fn Map
         un constructeur

      Le constructeur est la fonction membre appelee automatiquement lors de la creation d'un objet (en statique ou en dynamique).
       Cette fonction membre est la premiere fonction membre a etre executee, il s'agit donc d'une fonction permettant l'initialisation des variables.
    */
        Map();
        /*! \fn ~Map
        \brief un destructeur

      Le destructeurs sont en quelque sorte au constructeur ce que la mort est a la vie,
       c'est-a-dire qu'il s'agit d'une fonction membre qui intervient automatiquement lors de la destruction d'un objet.
    */
        virtual ~Map();
        /*! \fn LoadMap
        \brief Upload la carte
        \brief l'utilisation de loadMap c'est pour la creation de la carte.
        @param array on a utilise un tableau pour la creation de la carte

    */
        void LoadMap(int array[20][25]);
        /*! \fn DrawMap
        \brief Dessiner

      Dessiner ce qu'on a dessine
    */
        void DrawMap();
    /*! \fn getMap
    \brief un getteur Map

      Pour avoir les referances de la carte et l'utiliser dans GameObject pour limiter
      la circulation du joueur
    */
        int* getMap();

    protected:

    private:

        SDL_Rect src,dest;/*!< Un SDL_Rect definit en fait un rectangle mais on ne peut se servir que de la position si on veut.   */
        SDL_Texture* box;/*!< Declaration de la texture box */
        SDL_Texture* dirt;/*!< Declaration de la texture dirt */
        SDL_Texture * grass;/*!< Declaration de la texture  grass */
        SDL_Texture * floor;/*!< Declaration de la texture  floor */
        SDL_Texture * goal;/*!< Declaration de la texture  goal */

        int map[20][25];/*!< Declaration de la map pour l'utiliser dans GameObject */

};

#endif // MAP_H
