##
## EPITECH PROJECT, 2018
## make
## File description:
## it makes files
##

MAIN =	src/main.c

SRC	=	src/building/build_anthill.c \
		src/building/get_user_entry.c \
		src/building/tunnels.c \
		src/building/link.c \
		src/building/debug/debug_anthill.c \
		src/all_star/debug_all_star.c \
		src/all_star/all_star.c \

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

INCLUDE = ./include/

NAME	=	lemin

TEST_NAME	=	tests_a.out

CFLAGS = -I $(INCLUDE) -fdiagnostics-color

LIBS = -L lib/my/ -lmy -L lib/fae/ -lfae -L lib/list/ -llist

NORMAL = \033[0;39m

all:	$(NAME)

goodbye:
	@echo -ne "\033[1;5;34m"
	@echo -e " ___   ___  ___  ___  ___       ___"
	@echo -e "/   | |   ||   ||   \|   / \ / |    "
	@echo -e "|   __|   ||   ||   ||---\  |  |--  "
	@echo -e "|___/ |___||___||___/|___/  |  |___$(NORMAL)"

lib_make:
	@make -C lib/my
	@make -C lib/fae
	@make -C lib/list

lib_clean:
	@make clean -C lib/my
	@make clean -C lib/fae
	@make clean -C lib/list
	
lib_fclean:
	@make fclean -C lib/my
	@make fclean -C lib/fae
	@make fclean -C lib/list

$(NAME): lib_make $(OBJ)
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIBS)

clean: lib_clean
	@rm -f $(OBJ)

fclean: lib_fclean clean goodbye
	@rm -f $(NAME)

debug:	lib_make
	@gcc -o $(NAME) $(CFLAGS) $(MAIN) $(SRC) -g3 $(LIBS)
	@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

tests_run:	lib_make
	@echo -e "\033[1;95mRunning tests...\033[0;39m"
	@make -C lib/my
	@gcc -o $(TEST_NAME) $(CFLAGS) $(SRC) $(LIBS) --coverage -lcriterion
	./$(TEST_NAME)
	gcovr
	@echo -e "\033[1;94mTest finished, here are the results\033[0;39m"

re: fclean all
