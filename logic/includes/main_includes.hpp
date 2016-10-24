//
// main_includes.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas.home>
//
// Started on  Sun Apr  6 22:22:02 2014 Lucas Stil
// Last update Sun Apr  6 22:26:56 2014 Lucas Stil
//

#ifndef MAIN_INCLUDES_HPP_
# define MAIN_INCLUDES_HPP_

bool	convert_and_verify(const char *, const char *, int *, int *);
void	init_snake(snakeHead *, const int, const int);
void	getNomPos(const snakeHead &, const game &, nomNom *);
void	turnSnake(snakeHead *, gameKeys);
bool	ifCollision(const snakeHead &, const game &);
bool	goAhead(snakeHead *, nomNom *, const game &);
void	letsPlay(snakeHead, nomNom, const game &, display *);
void	init_and_play(const int, const int, const char *);

#endif /* !MAIN_INCLUDES_HPP_ */
