//
// nomNom.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas>
//
// Started on  Thu Apr  3 14:28:57 2014 Lucas Stil
// Last update Thu Apr  3 14:36:57 2014 Lucas Stil
//

#ifndef NOMNOM_HPP_
# define NOMNOM_HPP_

class nomNom
{
  public:
    nomNom(int, int);
    nomNom(const nomNom &);
    ~nomNom();
    nomNom operator=(const nomNom &);

    void setPos(int, int);

    int getXPos() const;
    int getYPos() const;

  private:
    int posX;
    int posY;
};

#endif /* !NOMNOM_HPP_ */
