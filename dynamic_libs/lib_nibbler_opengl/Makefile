##
## Makefile for  in /home/rouane_q/rendu/cpp_nibbler/dynamic_libs/lib_nibbler_opengl
##
## Made by quentin rouanet
## Login   <rouane_q@epitech.net>
##
## Started on  Fri Apr  4 15:14:20 2014 quentin rouanet
## Last update Sun Apr  6 22:32:34 2014 quentin rouanet
##

NAME=		lib_nibbler_opengl.so

SRC=		src/opengl.cpp \
		src/game.cpp \
		src/snake.cpp \
		src/nomNom.cpp \

OBJ=		$(SRC:.cpp=.o)

CXX=		g++

CXXFLAGS+=	-fPIC -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -shared -lSDLmain -lSDL  -lGL -lGLU -lm $(OBJ) -o $(NAME)
		@echo -e '\033[0;32m> Compiled\033[0m'

clean:
		rm -f $(OBJ)
		@echo -e '\033[0;31m> Directory cleaned\033[0m'

fclean:		clean
		rm -f $(NAME)
		@echo -e '\033[0;31m> Executable removed\033[0m'
re:		fclean all

.PHONY:		all clean fclean re
