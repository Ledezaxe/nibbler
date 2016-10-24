/*
** opengl.cpp for  in /home/rouane_q/projets/C++/nibbler
**
** Made by quentin rouanet
** Login   <rouane_q@epitech.net>
**
** Started on  Mon Mar 24 10:03:59 2014 quentin rouanet
// Last update Sun Apr  6 22:33:25 2014 quentin rouanet
*/

#include "../includes/opengl.hpp"
#include <math.h>
#include <iostream>

void draw_map();
void carre(float addx, float addy);
void cercle(float addx, float addy, int head);

void draw_map()
{
  glBegin(GL_QUADS);
  glColor3ub(97, 97, 97);
  glVertex2d(-1, -1);
  glVertex2d(-1, 1);
  glColor3ub(163, 163, 163);
  glVertex2d(1, 1);
  glVertex2d(1, -1);
  glEnd();
}

void carre(float addx, float addy)
{
  glBegin(GL_QUADS);
  glColor3ub(0, 0, 0);
  glVertex2d(addx - 0.1, addy - 0.1);
  glColor3ub(255, 72, 2);
  glVertex2d(addx - 0.1, addy + 0.1);
  glVertex2d(addx + 0.1, addy + 0.1);
  glVertex2d(addx + 0.1, addy - 0.1);
  glEnd();
}

void cercle(float addx, float addy, int head)
{
  float i;
  double mysin;
  double mycos;

  glBegin(GL_POLYGON);
  if (head == 0)
    glColor3ub(0, 255, 0);
  else
    glColor3ub(0, 0, 255);
  for (i=0 ; i<1000 ; i += 0.01)
    {
      mycos = 0.9 * cos(i * 2 * M_PI /1000);
      mysin = 0.9 * sin(i * 2 * M_PI /1000);
      glVertex2d(mycos / 10 + addx , mysin / 10 + addy);
    }
  glEnd();
}

OpenGl::OpenGl(const int width, const int length)
  : display(width, length)
{
  if (SDL_Init(SDL_INIT_VIDEO))
    {
      std::cout << "ERREUR : environnement manquant" << std::endl;
      exit(-1);
    }
  this->_largeur = length;
  this->_hauteur = width;
  SDL_WM_SetCaption("NIBBLER", NULL);
  SDL_SetVideoMode(this->_largeur * 30, this->_hauteur * 30, 32, SDL_OPENGL);
}

OpenGl::~OpenGl()
{
  SDL_Quit();
}

void OpenGl::gameOver(const game &stat)
{
  std::cout << "fin de partie !\nVotre score :" << stat.getScore() << std::endl;
}

void OpenGl::refreshScreen(const snakeHead & snake, const nomNom &food)
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw_map();
  this->draw_snake(snake);
  this->draw_food(food);
  glFlush();
  SDL_GL_SwapBuffers();
}

void OpenGl::draw_food(const nomNom &food)
{
  float x;
  float y;

  x = (float)(food.getXPos() - (this->_hauteur / 2)) / (this->_hauteur / 2);
  y = (float)(food.getYPos() - (this->_largeur / 2)) / (this->_largeur / 2);
  cercle(x, y, 0);
}

void OpenGl::draw_snake(const snakeHead& snake)
{
  std::queue<int> posx;
  std::queue<int> posy;
  float x;
  float y;

  x = (float)(snake.getPosX() - (this->_hauteur / 2)) / (this->_hauteur / 2);
  y = (float)(snake.getPosY() - (this->_largeur / 2)) / (this->_largeur / 2);
  carre(x, y);
  cercle(x, y, 1);
  posx = snake.getQueueX();
  posy = snake.getQueueY();
  while (!posx.empty())
    {
      x = (float)(posx.front() - (this->_hauteur / 2)) / (this->_hauteur / 2);
      y = (float)(posy.front() - (this->_largeur / 2)) / (this->_largeur / 2);
      carre(x, y);
      posx.pop();
      posy.pop();
    }
}

gameKeys OpenGl::getPressedKey()
{
  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
    return ESCAPE;
  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
    return ESCAPE;
  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
    return RIGHT;
  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
    return LEFT;
  return NONE;
}
