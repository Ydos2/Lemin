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
		src/building/debug/debug.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	lemin

TEST_NAME	=	tests_a.out

CFLAGS = -I include

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

$(NAME):	$(OBJ)	lib_make
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) -L lib/my/ -lmy

clean:
	@rm -f $(OBJ)

fclean: clean goodbye
	@make -C lib/my clean
	@rm -f $(NAME)

debug:	lib_make
	@gcc -o $(NAME) $(CFLAGS) $(MAIN) $(SRC) -g3 -L lib/my/ -lmy
	@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

tests_run:	lib_make
	@echo -e "\033[1;95mRunning tests...\033[0;39m"
	@make -C lib/my
	@gcc -o $(TEST_NAME) $(CFLAGS) $(SRC) -L lib/my/ -lmy --coverage -lcriterion
	./$(TEST_NAME)
	gcovr
	@echo -e "\033[1;94mTest finished, here are the results\033[0;39m"

re: fclean all
