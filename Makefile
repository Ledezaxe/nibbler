TARGETS=	nibbler libs

all:		$(TARGETS)

nibbler:
		# Compilation de nibbler...
		@cd ./logic ; make
		@ln -s logic/nibbler nibbler



libs:
		# Compilation des bibliothèques...
		@cd ./dynamic_libs ; make

clean:
		# Nettoyage des fichiers objet...
		@cd ./logic ; make clean
		@cd ./dynamic_libs ; make clean

fclean:
		# Nettoyage des exécutables et des bibliothèques...
		@cd ./logic ; make fclean
		@cd ./dynamic_libs ; make fclean
		rm -f nibbler
		rm -f *.so

re:		fclean all

.PHONY:		libs clean fclean re
