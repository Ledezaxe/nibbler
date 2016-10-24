/*
** opengl.h for  in /home/rouane_q/projets/C++/nibbler
**
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
**
** Started on  Tue Apr  1 17:06:31 2014 quentin rouanet
// Last update Sun Apr  6 16:10:47 2014 quentin rouanet
*/
#ifndef OPENGL_H_
# define OPENGL_H_

#include "display.hpp"

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class OpenGl : public display
{
  public:
  OpenGl(const int, const int);
  virtual ~OpenGl();

  SDL_Event event;
  int _largeur;
  int _hauteur;

  void draw_snake(const snakeHead&);
  void draw_food(const nomNom&);
  virtual void refreshScreen(const snakeHead &, const nomNom&);
  virtual gameKeys getPressedKey();
  virtual void gameOver(const game &);
};

extern "C" display *create(const int, const int);
extern "C" void	destroy(display *);

extern "C" display* create(const int width, const int length)
{
  return new OpenGl(width, length);
}

extern "C" void destroy(display* disp)
{
  delete disp;
}

#endif
