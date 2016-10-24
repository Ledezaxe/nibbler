##
## Makefile for  in /home/rouane_q/rendu/cpp_nibbler/dynamic_libs/lib_nibbler_opengl
##
## Made by quentin rouanet
## Login   <rouane_q@epitech.net>
##
## Started on  Fri Apr  4 15:14:20 2014 quentin rouanet
## Last update Sun Apr  6 22:34:21 2014 Lucas Stil
##

NAME=		lib_nibbler_allegro.so

SRC=		src/allegro.cpp \
		src/game.cpp \
		src/snake.cpp \
		src/nomNom.cpp \

OBJ=		$(SRC:.cpp=.o)

CXX=		g++

CXXFLAGS+=	-fPIC -Wall -Wextra

ALLEGRO=	$(shell pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 \
		allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 \
		allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 \
		allegro_ttf-5.0)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -shared $(ALLEGRO) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
