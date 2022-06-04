#ifndef GAME_H
#define GAME_H
#include <string>
/*! \package iostream
    \brief pour inclure des objets de flux globaux dans c++.

*/
#include <iostream>
/*! \package stdio
    \brief pour  Standard Input Output Header  ou  En-tete Standard d'Entree/Sortie

*/
#include <stdio.h>
/*! \package SDL2
    \brief une bibliotheque utilisee en programmation multimedia.
*/
#include <SDL2/SDL.h>
/*! \package SDL2image
    \brief Il est construit sur le framework OpenGL et utilise SDL pour la lectures des images.

*/
#include <SDL2/SDL_image.h>


/*! \class Game
    \brief une class du jeu.

    l'utilisation de cette a etait necessaire pour afficher et dessiner
    et rafraichir les dessins et la fenetre.
*/



class Game
{
    public:
                /*! \fn Game
               \brief  un constructeur

      Le constructeur est la fonction membre appelee automatiquement lors de la creation d'un objet (en statique ou en dynamique).
       Cette fonction membre est la premiere fonction membre a etre executee, il s'agit donc d'une fonction permettant l'initialisation des variables.
    */
        Game();
            /*! \fn ~Game
            \brief un destructeur

      Le destructeurs sont en quelque sorte au constructeur ce que la mort est a la vie,
       c'est-a-dire qu'il s'agit d'une fonction membre qui intervient automatiquement lors de la destruction d'un objet.
    */
        virtual ~Game();
        /*! \fn init
        \brief initialisation.

      on doit initialiser, pour cela nous recourons a cette fonction d'initialisation
      ou on peut saisir le chemin de l'image et ces references

      @param title le lien de l'image
      @param xpos la position x
      @param ypos la position y
      @param widhtpos la largeur
      @param heightpos la taille
      @param fullscreen plein ecran
    */
        void init(const char* title, int xpos,int ypos,int widhtpos,int heightpos, bool fullscreen);
            /*! \fn handleEvents
            \brief Gerer les evenements

      Nous appelons evenement toute action exterieure a notre programme et qui peut avoir un effet sur lui. L'appui sur une touche du clavier, le deplacement de la souris,
       le redimensionnement d'une fenetre, et meme une demande de fermeture du programme sont des evenements.

    */
        void handleEvents();

            /*! \fn update
            \brief Rafraichir l'image

      Mettre a jour la fenetre
    */
        void update();
        /*! \fn render
        \brief Dessiner

      Dessiner ce qu'on a a dessiner
    */
        void render();
        /*! \fn clean
        \brief Nettoyer

      Nettoyer le contenu actuel de la fenetre
    */
        void clean();
        /*! \fn running
        \brief booleen

      @return si la fenetre et toujours ON
    */
        bool running(){return isRunning;}

        static SDL_Renderer *renderer; /*!< Declaration pour Renouveler l'affichage  */
        static SDL_Event event; /*!< Declaration pour l'evenement*/
    protected:

    private:

        bool isRunning;/*!< Declaration du boolean  */
        SDL_Window *window;/*!< Declaration de la fenetre  */
};

#endif // GAME_H
