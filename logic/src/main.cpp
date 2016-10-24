#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <time.h>

#include "../includes/libraryHandler.hpp"
#include "../includes/display.hpp"
#include "../includes/main.hpp"
#include "../includes/main_includes.hpp"

bool		convert_and_verify(const char *strW, const char *strL,
				   int *width, int *length)
{
  std::istringstream(strW) >> *width;
  std::istringstream(strL) >> *length;
  if (*length < 10 || *length > 50 || *width < 10 || *width > 50)
    return false;
  return true;
}

void			init_snake(snakeHead *snake, const int width,
				   const int length)
{
  snake->pushX((width / 2));
  snake->pushX((width / 2));
  snake->pushY((length / 2 ) - 1);
  snake->pushY((length / 2 ) - 2);
 }

void			getNomPos(const snakeHead &snake, const game &g,
				  nomNom *miam)
{
  bool			found = false;
  long int		tempX = 0, tempY = 0;
  std::queue<int>	qX, qY;

  while (!found)
    {
      qX = snake.getQueueX();
      qY = snake.getQueueY();
      tempX = random() % g.getXSize();
      tempY = random() % g.getYSize();
      if (tempX == snake.getPosX() && tempY == snake.getPosY())
	continue;
      while (qX.empty() == false)
	{
	  if (qX.front() == tempX && qY.front() == tempY)
	    break;
	  qX.pop();
	  qY.pop();
	}
      if (qX.empty() == true)
	found = true;
    }
  miam->setPos((int)tempX, (int)tempY);
}

void			turnSnake(snakeHead *snake, gameKeys key)
{
  if (key == RIGHT)
    {
      if (snake->getDirection() == LE)
	snake->setDirection(UP);
      else if (snake->getDirection() == UP)
	snake->setDirection(RI);
      else if (snake->getDirection() == RI)
	snake->setDirection(DOWN);
      else if (snake->getDirection() == DOWN)
	snake->setDirection(LE);
    }
  else if (key == LEFT)
    {
      if (snake->getDirection() == UP)
	snake->setDirection(LE);
      else if (snake->getDirection() == LE)
	snake->setDirection(DOWN);
      else if (snake->getDirection() == DOWN)
	snake->setDirection(RI);
      else if (snake->getDirection() == RI)
	snake->setDirection(UP);
    }
}

bool			ifCollision(const snakeHead &snake, const game &g)
{
  std::queue<int>	qX = snake.getQueueX(), qY = snake.getQueueY();

  if ((snake.getPosX() < 0 || snake.getPosX() == g.getXSize())
      || (snake.getPosY() < 0 || snake.getPosY() == g.getYSize()))
    return (true);
  while (qX.empty() != true)
    {
      if (snake.getPosX() == qX.front() && snake.getPosY() == qY.front())
	return (true);
      qX.pop();
      qY.pop();
    }
  return (false);
}

bool			goAhead(snakeHead *snake, nomNom *miam, const game &g)
{
  snake->pushX(snake->getPosX());
  snake->pushY(snake->getPosY());
  if (snake->getDirection() == UP)
    snake->setPosY(snake->getPosY() + 1);
  else if (snake->getDirection() == DOWN)
    snake->setPosY(snake->getPosY() - 1);
  else if (snake->getDirection() == LE)
    snake->setPosX(snake->getPosX() - 1);
  else if (snake->getDirection() == RI)
    snake->setPosX(snake->getPosX() + 1);
  if (snake->getPosX() != miam->getXPos() ||
      snake->getPosY() != miam->getYPos())
    {
      snake->popX();
      snake->popY();
    }
  else
    getNomPos(*snake, g, miam);
  return (ifCollision(*snake, g));
}

void			letsPlay(snakeHead snake, nomNom miam, const game &g,
				 display *disp)
{
  bool			quit = false;
  gameKeys		key;

  while (!quit)
    {
      key = disp->getPressedKey();
      if (key == LEFT || key == RIGHT)
	turnSnake(&snake, key);
      if (key == ESCAPE)
	{
	  quit = true;
	  continue;
	}
      quit = goAhead(&snake, &miam, g);
      disp->refreshScreen(snake, miam);
      usleep(70000);
    }
}

void			init_and_play(const int width, const int length,
				      const char *library)
{
  libraryHandler	handler(library);
  create_t		*load_lib;
  destroy_t		*unload_lib;
  snakeHead		snake(width / 2, length / 2);
  nomNom		miam(0, 0);
  game			g(width, length);

  if ((load_lib = (create_t*)dlsym(handler.getHandle(), "create")) == NULL)
    throw dlerror();
  if ((unload_lib = (destroy_t*)dlsym(handler.getHandle(), "destroy")) == NULL)
    throw dlerror();

  init_snake(&snake, width, length);
  getNomPos(snake, g, &miam);
  display *disp = (*load_lib)(width, length);
  letsPlay(snake, miam, g, disp);
  unload_lib(disp);
}

int	main(int argc, char **argv)
{
  int	width = 0, length = 0;

  srandom((unsigned int)time(NULL));
  if (argc != 4)
    {
      std::cout << "Usage : " << argv[0] << " width height dynamic_library\n";
      return (1);
    }
  if (!convert_and_verify(argv[1], argv[2], &width, &length))
    {
      std::cout << "Valeur de taille invalide !\n";
      return (1);
    }
  try
    {
      init_and_play(width, length, argv[3]);
    }
  catch(char *msg)
    {
      std::cerr << msg << std::endl;
    }
  return (0);
}
