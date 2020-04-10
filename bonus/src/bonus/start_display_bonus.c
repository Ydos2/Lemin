/*
** EPITECH PROJECT, 2020
** start_display_bonus
** File description:
** start_display_bonus
*/

#include <ncurses.h>
#include "main.h"
#include "bonus.h"

static void update_camera(int input, screen_t *screen)
{
    switch (input) {
        case KEY_LEFT:
            clear();
            screen->x--;
            break;
        case KEY_RIGHT:
            clear();
            screen->x++;
            break;
        case KEY_UP:
            clear();
            screen->y--;
            break;
        case KEY_DOWN:
            clear();
            screen->y++;
            break;
    }
}

static void diplay_node(lm_tunnel_t **tunnels, screen_t *screen)
{
    attron(COLOR_PAIR(3));
    for (int nbr = 0; tunnels[nbr] != NULL; nbr++) {
        mvprintw(tunnels[nbr]->y + screen->y,
            tunnels[nbr]->x + screen->x, " ");
    }
}

void start_display_bonus(lm_tunnel_t **tunnels, path_t *paths)
{
    int input = 0;
    int size[2];
    screen_t *screen = malloc(sizeof(screen_t));

    initialise_ncurse(screen);
    while (input != ' ') {
        getmaxyx(stdscr, size[1], size[0]);
        input = getch();
        update_camera(input, screen);
        diplay_node(tunnels, screen);
        refresh();
    }
    end_ncurses();
    free(screen);
}