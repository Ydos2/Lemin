##
## EPITECH PROJECT, 2018
## make
## File description:
## it makes files
##

MAIN =	src/main.c

SRC	=	src/building/build_anthill.c 			\
		src/building/get_user_entry.c 			\
		src/building/tunnels.c 					\
		src/building/link.c 					\
		src/building/command.c 					\
		src/building/debug/debug_anthill.c 		\
		src/all_star/debug_all_star.c 			\
		src/all_star/all_star.c 				\
		src/all_star/node.c 					\
		src/all_star/all_star_utils.c 			\
		src/all_star/create_path.c 				\
		src/ant_management/get_shortest_paths.c	\
		src/ant_management/ants_movements.c		\
		src/display/display.c					\
		src/display/display_movements_stdout.c	\
		src/debug.c				 				\
		src/bonus/initialise_ncurses.c			\
		src/bonus/start_display_bonus.c			\
		src/bonus/end_ncurses.c					\

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

INCLUDE = ./include/ ./bonus.h

NAME	=	lem_in_bonus

TEST_NAME	=	unit_tests

CFLAGS = -I./include -Wextra -W -Wall -pedantic -fdiagnostics-color -lncurses

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
	@rm -f $(OBJ) $(COVERAGE)
	@rm -f *.gcda
	@rm -f *.gcno

fclean: lib_fclean clean goodbye
	@rm -f $(NAME)

debug:	lib_make
	@gcc -o $(NAME) $(CFLAGS) $(MAIN) $(SRC) $(BONUS) -g3 $(LIBS)
	@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

re: fclean all ## Clean then compile

valgrind:	CFLAGS += -g3
valgrind:	fclean	all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help
