/*
** Ncurses.cpp for Ncurses in /home/langros/Rendu/Ncurses
** 
** Made by sonia langrognat
** Login   <langro_s@epitech.eu>
** 
** Started on  Wed Apr  2 13:26:27 2014 sonia langrognat
** Last update Sat Apr  5 19:54:39 2014 sonia langrognat
*/

#include		<stdio.h>

#include			<iostream>
#include			<stdlib.h>
#include			<ncurses.h>
#include			"../includes/Ncurses.hpp"

gameKeys			NCurses::getPressedKey()
{
  int				k;

  k = getch();
  if (k == 260)
    return LEFT;
  else if (k == 261)
    return RIGHT;
  else if (k == 27)
    return ESCAPE;
  else
    return NONE;
}

void				NCurses::snakeDisplay(const snakeHead &sh, const nomNom &nn)
{
  std::queue<int>		posx;
  std::queue<int>		posy;
  int i, j;
  i = 1;
  j = 1;

  while (i < (_w - 1))
    {
      while (j < (_h -1))
	{
	  squareDisplay(i, j, " ");
	  j++;
	}
      j = 0;
      i++;
    }
  squareDisplay(sh.getPosY(), sh.getPosX(), "o");
  posx = sh.getQueueX();
  posy = sh.getQueueY();
  while (!posx.empty())
    {
      squareDisplay(posy.front(),posx.front(),"*");
      posx.pop();
      posy.pop();
    }
  squareDisplay(nn.getYPos(), nn.getXPos(), "x");
}

void				NCurses::squareDisplay(int x, int y, std::string img)
{
  if (wmove(this->_wind, y, x) == ERR || waddstr(this->_wind, img.c_str()) == ERR)
    exit(-1);
}

void				NCurses::mapDisplay()
{
  if (wborder(this->_wind, '|', '|', '-', '-', '+', '+', '+', '+') == ERR)
    exit(-1);
}

void				NCurses::refreshScreen(const snakeHead &sh, const nomNom &nn)
{
  snakeDisplay(sh, nn);
  if (refresh() == ERR || wrefresh(this->_wind) == ERR)
      exit(-1); 
}

void				NCurses::gameOver(const game&)
{
}


NCurses::NCurses(unsigned int w, unsigned int h)
  : display((int)w, (int)h), _w(w + 2), _h(h + 2), _wind(NULL)
{
  int			line;
  int			column;

  if (initscr() == NULL || noecho() == ERR || keypad(stdscr, TRUE) == ERR
      || curs_set(0) == ERR || (this->_wind = newwin(_h, _w, 0, 0)) == NULL || nodelay(stdscr, TRUE) == ERR
      || box(_wind, 0, 0) == ERR || getmaxyx(stdscr, line, column) == ERR)
    {
      exit(-1); 
    }
  if (column < _w || line < _w)
    {
      exit(-1); 
    }
  mapDisplay();
}

NCurses::~NCurses()
{
  if (this->_wind != NULL)
    delwin(this->_wind);
  endwin();  
}
