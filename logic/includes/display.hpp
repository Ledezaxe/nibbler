//
// display.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas>
//
// Started on  Thu Apr  3 17:57:06 2014 Lucas Stil
// Last update Sat Apr  5 19:22:57 2014 Lucas Stil
//

#ifndef DISPLAY_HPP_
# define DISPLAY_HPP_

#include "nomNom.hpp"
#include "snake.hpp"
#include "main.hpp"
#include "game.hpp"

class display
{
  public:
    display(const int, const int) {}
    virtual ~display();

    virtual void refreshScreen(const snakeHead &, const nomNom &) = 0;
    virtual gameKeys getPressedKey() = 0;
    virtual void gameOver(const game &) = 0;
};

display::~display()
{}

typedef display*	create_t(const int, const int);
typedef void		(destroy_t)(display *);

// À utiliser avec les factories !

// Exemple avec la classe "actualDisplay" (tout affichage doit avoir le même nom) :

// extern "C" display* create()
// {
//   return (new actualDisplay);
// }

// extern "C" void destroy(display* disp)
// {
//   delete disp;
// }

// Voir http://www.tldp.org/HOWTO/html_single/C++-dlopen/ section 3.3

#endif /* !DISPLAY_HPP_ */
