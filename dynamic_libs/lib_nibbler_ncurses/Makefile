##
## Makefile for  in /home/langros/Rendu/cpp_nibbler/dynamic_libs/Ncurses
##
## Made by sonia langrognat
## Login   <langros@epitech.net>
##
## Started on  Sat Apr  5 13:02:20 2014 sonia langrognat
## Last update Sun Apr  6 15:46:22 2014 Lucas Stil
##

NAME		= lib_nibbler_ncurses.so

SRC		= src/Ncurses.cpp \
		  src/game.cpp \
		  src/nomNom.cpp \
		  src/snake.cpp

OBJ		= $(SRC:.cpp=.o)

CXX		= g++ -fPIC

CXXFLAGS+	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -shared -fpic -lncurses $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
