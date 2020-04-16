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
		src/building/command.c \
		src/building/debug/debug_anthill.c \
		src/error_management.c\
		src/all_star/debug_all_star.c \
		src/all_star/all_star.c \
		src/all_star/node.c \
		src/all_star/all_star_utils.c \
		src/all_star/create_path.c \
		src/ant_management/get_shortest_paths.c\
		src/ant_management/ants_movements.c\
		src/display/display.c\
		src/display/display_movements_stdout.c\
		src/debug.c \

TESTS	=	tests/tests_lib/lib_tests_getnbr.c			\
			tests/tests_lib/lib_tests_compute.c			\
			tests/tests_src/src_tests_initialisation.c	\

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

COVERAGE	=	$(MAIN:.c=.gcda)	\
				$(MAIN:.c=.gcno)	\
				$(TESTS:.c=.gcda)	\
				$(TESTS:.c=.gcno)	\
				$(SRC:.c=.gcda)	\
				$(SRC:.c=.gcno)

INCLUDE = ./include/

NAME	=	lem_in

NAME_BONUS	=	lem_in_bonus

TEST_NAME	=	unit_tests

CFLAGS = -I./include -Wextra -W -Wall -pedantic -fdiagnostics-color

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

bonus_make:
	@cp ./include ./bonus/include -rf
	@cp ./src/all_star ./bonus/src/all_star -rf
	@cp ./src/ant_management ./bonus/src/ant_management -rf
	@cp ./src/building ./bonus/src/building -rf
	@cp ./src/display ./bonus/src/display -rf
	@cp ./src/debug.c ./bonus/src/debug.c -rf
	@make re -C bonus
	@cp ./bonus/lem_in_bonus ./ -rf
bonus_clean:
	@make clean -C bonus

bonus_fclean:
	@rm	./bonus/include/include -rf
	@rm ./bonus/src/all_star -rf
	@rm ./bonus/src/ant_management -rf
	@rm ./bonus/src/building -rf
	@rm ./bonus/src/display -rf
	@rm ./bonus/src/debug.c -rf
	@make fclean -C bonus

$(NAME): lib_make $(OBJ)
	@gcc -o $(NAME) $(CFLAGS) $(OBJ) $(LIBS)

clean: lib_clean bonus_clean
	@rm -f $(OBJ) $(COVERAGE)
	@rm -f *.gcda
	@rm -f *.gcno

fclean: lib_fclean bonus_fclean clean goodbye
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

debug:	lib_make
	@gcc -o $(NAME) $(CFLAGS) $(MAIN) $(SRC) -g3 $(LIBS)
	@echo -e "\033[1;91mDebug mod enabled !\033[0;39m"

bonus:	bonus_make
	@echo -e "\033[1;91mBonus mod enabled !\033[0;39m"

tests_run:	lib_make ## Launch tests
	@echo -e "\033[1;31mCOMPILING TESTS...\033[0;39m"
	@make -C lib/my
	@gcc -o $(TEST_NAME) $(CFLAGS) $(SRC) $(TESTS) $(LIBS) --coverage -lcriterion
	./$(TEST_NAME)
	gcovr
	gcovr -b
	@echo -e "\033[1;94mTest finished, here are the results\033[0;39m"

re_tests: fclean tests_run ## Clean then tests

re: fclean all ## Clean then compile

valgrind:	CFLAGS += -g3
valgrind:	fclean	all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help
