/*
** EPITECH PROJECT, 2020
** end_ncurses
** File description:
** end_ncurses
*/

#include <ncurses.h>
#include "bonus.h"

void end_ncurses(void)
{
    clear();
    getch();
    endwin();
}