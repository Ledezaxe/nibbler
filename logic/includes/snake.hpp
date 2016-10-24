//
// snake.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas>
//
// Started on  Mon Mar 24 13:56:54 2014 Lucas Stil
// Last update Sun Apr  6 19:55:38 2014 Lucas Stil
//

#ifndef SNAKE_HPP_
# define SNAKE_HPP_

#include <queue>

enum	snakeFace
{
  UP,
  RI,
  DOWN,
  LE
};

class snakeHead
{
  public:
    snakeHead(const int, const int);
    snakeHead(const snakeHead &);
    ~snakeHead(void);
    snakeHead operator=(const snakeHead &);

    int getPosX(void) const;
    int getPosY(void) const;
    int frontX(void) const;
    int frontY(void) const;
    std::queue<int> getQueueX(void) const;
    std::queue<int> getQueueY(void) const;
    snakeFace getDirection(void) const;
    bool isQueueXEmpty(void) const;
    bool isQueueYEmpty(void) const;

    void setDirection(const snakeFace &);
    void setPosX(const int);
    void setPosY(const int);
    void pushX(const int);
    void pushY(const int);
    void popX(void);
    void popY(void);

  private:
    int	posX;
    int	posY;
    std::queue<int> queueX;
    std::queue<int> queueY;
    snakeFace goingTo;
};

#endif /* SNAKE_HPP_ */
