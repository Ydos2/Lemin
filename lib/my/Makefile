##
## EPITECH PROJECT, 2018
## makefile
## File description:
## it makes files
##

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	@echo -e "\033[1;93mCompiling lib....\033[0;39m"
	gcc -c *.c
	ar rc $(NAME) *.o
	@echo -e "\033[1;32mLib successfully compiled !\033[0;39m"

clean:
	rm -f *.o
	rm -f $(NAME)
	rm -f ../$(NAME)

re: clean all