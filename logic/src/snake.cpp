#include "../includes/snake.hpp"


// Constructors
snakeHead::snakeHead(const int x, const int y)
  : posX(x), posY(y)
{}

snakeHead::snakeHead(const snakeHead &to_copy)
  : posX(to_copy.getPosX()), posY(to_copy.getPosY()),
    queueX(to_copy.getQueueX()), queueY(to_copy.getQueueY()), goingTo(UP)
{}

snakeHead::~snakeHead(void)
{}

snakeHead	snakeHead::operator=(const snakeHead &to_copy)
{
  this->posX = to_copy.getPosX();
  this->posY = to_copy.getPosY();
  this->queueX = to_copy.getQueueX();
  this->queueY = to_copy.getQueueY();
  return (*this);
}


// Getters
int		snakeHead::getPosX(void) const
{
  return (this->posX);
}

int		snakeHead::getPosY(void) const
{
  return (this->posY);
}

int		snakeHead::frontX(void) const
{
  return (this->queueX.front());
}

int		snakeHead::frontY(void) const
{
  return (this->queueY.front());
}

std::queue<int>	snakeHead::getQueueX(void) const
{
  return (this->queueX);
}

std::queue<int>	snakeHead::getQueueY(void) const
{
  return (this->queueY);
}

snakeFace	snakeHead::getDirection(void) const
{
  return (this->goingTo);
}

bool		snakeHead::isQueueXEmpty(void) const
{
  return (this->queueX.empty());
}

bool		snakeHead::isQueueYEmpty(void) const
{
  return (this->queueY.empty());
}

// Setters
void		snakeHead::setPosX(const int x)
{
  this->posX = x;
}

void		snakeHead::setPosY(const int y)
{
  this->posY = y;
}

void		snakeHead::pushX(const int x)
{
  this->queueX.push(x);
}

void		snakeHead::pushY(const int y)
{
  this->queueY.push(y);
}

void		snakeHead::popX(void)
{
  this->queueX.pop();
}

void		snakeHead::popY(void)
{
  this->queueY.pop();
}

void		snakeHead::setDirection(const snakeFace &direction)
{
  this->goingTo = direction;
}
