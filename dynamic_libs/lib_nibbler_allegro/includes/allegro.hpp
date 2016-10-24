//
// allegro.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/dynamic_libs/lib_nibbler_allegro
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas.home>
//
// Started on  Sun Apr  6 16:33:02 2014 Lucas Stil
// Last update Sun Apr  6 18:11:51 2014 Lucas Stil
//

#ifndef ALLEGRO_HPP_
# define ALLEGRO_HPP_

#include "display.hpp"

#include <allegro5/allegro.h>

# define SQUARE_SIZE 10

class allegro : public display
{
  public:
    allegro(const int, const int);
    virtual ~allegro();

    virtual void refreshScreen(const snakeHead &, const nomNom&);
    virtual gameKeys getPressedKey();
    virtual void gameOver(const game &);

  private:
    ALLEGRO_DISPLAY *window;
    ALLEGRO_EVENT_QUEUE *event_queue;
};

extern "C" display *create(const int, const int);
extern "C" void	destroy(display *);

extern "C" display* create(const int width, const int length)
{
  return new allegro(width, length);
}

extern "C" void destroy(display* disp)
{
  delete disp;
}

#endif /* !ALLEGRO_HPP_ */
