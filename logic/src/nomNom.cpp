#include "../includes/nomNom.hpp"

nomNom::nomNom(int x, int y)
  : posX(x), posY(y)
{}

nomNom::nomNom(const nomNom &to_copy)
  : posX(to_copy.getXPos()), posY(to_copy.getYPos())
{}

nomNom::~nomNom()
{}

nomNom	nomNom::operator=(const nomNom &to_copy)
{
  this->posX = to_copy.getXPos();
  this->posY = to_copy.getYPos();
  return (*this);
}

void	nomNom::setPos(int x, int y)
{
  this->posX = x;
  this->posY = y;
}

int	nomNom::getXPos() const
{
  return (this->posX);
}

int	nomNom::getYPos() const
{
  return (this->posY);
}
