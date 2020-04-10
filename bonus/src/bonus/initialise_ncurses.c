/*
** EPITECH PROJECT, 2020
** initialise_ncurses
** File description:
** initialise_ncurses
*/

#include <ncurses.h>
#include "bonus.h"

static void init_pair_void(void)
{
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(3, COLOR_WHITE, COLOR_RED);
    init_pair(4, COLOR_WHITE, COLOR_GREEN);
    init_pair(5, COLOR_WHITE, COLOR_CYAN);
    init_pair(6, COLOR_WHITE, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
}

void initialise_ncurse(screen_t *screen)
{
    int	index[2];

    screen->x = 0;
    screen->y = 0;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    start_color();
    clear();
    init_pair_void();
}