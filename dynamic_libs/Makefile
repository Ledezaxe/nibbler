TARGETS=	 opengl allegro ncurses #ajouter les libs ici

all:		$(TARGETS)

opengl:
		cd ./lib_nibbler_opengl ; make

allegro:
		cd ./lib_nibbler_allegro ; make

ncurses:
		cd ./lib_nibbler_ncurses ; make

clean:
		cd ./lib_nibbler_allegro ; make clean
		cd ./lib_nibbler_ncurses ; make clean
		cd ./lib_nibbler_opengl ; make clean
#		Mettre d'autres libs ici

fclean:
		cd ./lib_nibbler_allegro ; make fclean
		rm -f lib_nibbler_allegro.so
		cd ./lib_nibbler_ncurses ; make fclean
		rm -f lib_nibbler_ncurses.so
		cd ./lib_nibbler_opengl ; make fclean
		rm -f lib_nibbler_opengl.so
#		Mettre d'autres libs ici

re:
		cd ./lib_nibbler_allegro ; make re
		cd ./lib_nibbler_opengl ; make re
		cd ./lib_nibbler_ncurses ; make re
#		Mettre d'autres libs ici
