#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
/*! \package pragmaOnce
    /*!
      \brief ce package permet d'utiliser les classes une seule fois
      pour eviter la repition.
    */
#pragma once
#include "Game.h"
#include "Map.h"
/*! \class GameObject
    \brief classe d'Objet


      cette classe sert a la modification et la manipulation du joueur ou objet
      par ex : ces position,taille...
    */
class GameObject
{
    public:
        /*! \fn getPosX
        \brief un getteur X

      Pour avoir la position du x
    */
        int getPosX();
        /*! \fn getY
        \brief un getteur Y

      Pour avoir la position du y
    */
        int getY();
        /*! \fn GameObject
         \brief un constructeur

      Le constructeur est la fonction membre appelee automatiquement lors de la creation d'un objet (en statique ou en dynamique).
       Cette fonction membre est la premiere fonction membre a etre executee, il s'agit donc d'une fonction permettant l'initialisation des variables.
       Avec 3 para
       @param texturesheet le lien de l'image
       @param x position x
       @param y position y
    */
        GameObject(const char* texturesheet,int x,int y);
        /*! \fn ~GameObject
         \brief un destructeur

      Le destructeurs sont en quelque sorte au constructeur ce que la mort est a la vie,
       c'est-a-dire qu'il s'agit d'une fonction membre qui intervient automatiquement lors de la destruction d'un objet.
    */
        virtual ~GameObject();
        bool setX(int x , Map* m);
        bool setY(int y, Map* m);
        /*! \fn Update
       \brief  Rafraichir l'image

      Mettre a jour la fenetre
    */
        void Update();
        /*! \fn Render
        \brief Dessiner

      Dessiner ce qu'on a a dessiner
    */
        void Render();

    protected:

    private:

        int xpos;/*!< Declaration pour avoir pos x  */
        int ypos;/*!< Declaration pour avoir pos y  */
        SDL_Event event;/*!< Declaration pour l'evenement*/
        SDL_Texture* objTexture;/*!< Declaration de la texture  */
        SDL_Rect srcRect, destRect;/*!< Un SDL_Rect definit en fait un rectangle mais on ne peut se servir que de la position si on veut.   */


};

#endif // GAMEOBJECT_H
