#include "../includes/game.hpp"

// Constructors

game::game(int x, int y)
  : xSize(x), ySize(y), score(0)
{}

game::game(const game &to_copy)
  : xSize(to_copy.getXSize()), ySize(to_copy.getYSize()),
    score(to_copy.getScore())
{}

game::~game()
{}

game	game::operator=(const game &to_copy)
{
  this->xSize = to_copy.getXSize();
  this->ySize = to_copy.getYSize();
  this->score = to_copy.getScore();
  return (*this);
}

//Setters
void	game::incrScore()
{
  this->score += 1;
}

// Getters
int	game::getXSize() const
{
  return (this->xSize);
}

int	game::getYSize() const
{
  return (this->ySize);
}

int	game::getScore() const
{
  return (this->score);
}
