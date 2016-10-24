NAME=		nibbler

SRC=		src/main.cpp \
		src/snake.cpp \
		src/game.cpp \
		src/nomNom.cpp \
		src/libraryHandler.cpp

OBJ=		$(SRC:.cpp=.o)

CXX=		g++

CXXFLAGS+=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(CXXFLAGS) -ldl -fPIC $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
