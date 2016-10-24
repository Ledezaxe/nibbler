/*
** Ncurses.hpp for Ncurses in /home/langros/Rendu/Ncurses
**
** Made by sonia langrognat
** Login   <langro_s@epitech.eu>
**
** Started on  Wed Apr  2 13:02:15 2014 sonia langrognat
// Last update Sat Apr  5 17:46:27 2014 Lucas Stil
*/

#ifndef			NCURSES_HPP_
# define		NCURSES_HPP_

#include		<ncurses.h>
#include		<string>
#include		<stdexcept>
#include		"display.hpp"
#include		"game.hpp"
#include		"nomNom.hpp"
#include		"snake.hpp"
#include		"main.hpp"

class			NCurses : public display
{
public:
  virtual gameKeys	getPressedKey(void);
  virtual void		initDisplay(const int, const int) {};
  void			snakeDisplay(const snakeHead &sh, const nomNom &nm);
  void			squareDisplay(int x, int y, std::string img);
  void			mapDisplay(void);
  void			cleanWindow(void);
  virtual void          gameOver(const game &);
  virtual void		refreshScreen(const snakeHead&, const nomNom&);

  NCurses(unsigned int, unsigned int);
  ~NCurses(void);;

private:
  int			_w;
  int			_h;
  WINDOW		*_wind;
};

extern "C" display *create(const int, const int);
extern "C" void	destroy(display *);

extern "C" display* create(const int width, const int length)
{
  return new NCurses(width, length);
}

extern "C" void destroy(display* disp)
{
  delete disp;
}



#endif /* !NCURSES_HPP_ */
