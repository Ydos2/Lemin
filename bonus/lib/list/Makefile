##
## EPITECH PROJECT, 2020
## list
## File description:
## Makefile
##

SRC	=	dep/list_put_nbr.c		\
		dep/list_putchar.c		\
		linked_list.c			\
		linked_list_free.c		\
		linked_list_pop.c		\
		linked_list_swap.c		\
		linked_list_add_node.c	\
		linked_list_transfer.c	\
		linked_list_iswap.c		\
		linked_list_rotate.c	\
		linked_list_get_length.c\
		linked_list_merge.c		\

OBJ	=	$(SRC:.c=.o)

NAME =	liblist.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp linked_list.h ../../include

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
