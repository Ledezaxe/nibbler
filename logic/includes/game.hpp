//
// game.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas>
//
// Started on  Tue Apr  1 17:17:30 2014 Lucas Stil
// Last update Thu Apr  3 14:24:41 2014 Lucas Stil
//

#ifndef GAME_HPP_
# define GAME_HPP_

class game
{
  public:
    game(int, int);
    game(const game &);
    ~game();
    game operator=(const game &);

    void incrScore();

    int getXSize() const;
    int getYSize() const;
    int	getScore() const;

  private:
    int xSize;
    int ySize;
    int score;
};

#endif /* !GAME_HPP_ */
