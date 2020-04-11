/*
** EPITECH PROJECT, 2020
** start_display_bonus
** File description:
** start_display_bonus
*/

#include <ncurses.h>
#include "main.h"
#include "bonus.h"

static int update_camera(int input, screen_t *screen)
{
    switch (input) {
        case KEY_LEFT:
            clear();
            screen->x--;
            return (1);
        case KEY_RIGHT:
            clear();
            screen->x++;
            return (1);
        case KEY_UP:
            clear();
            screen->y--;
            return (1);
        case KEY_DOWN:
            clear();
            screen->y++;
            return (1);
    }
    return (0);
}

static int diplay_node(lm_tunnel_t **tunnels,
    screen_t *screen, path_t *paths, int turn)
{
    int nbr_turn = 0;

    attron(COLOR_PAIR(3));
    for (int nbr = 0; tunnels[nbr] != NULL; nbr++) {
        mvprintw(tunnels[nbr]->y + screen->y,
            tunnels[nbr]->x + screen->x, " ");
    }
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    for (; paths->path[nbr_turn] != NULL; nbr_turn++);
    for (int nbr = 0; nbr != turn; nbr++) {
        mvprintw(paths->path[nbr]->y + screen->y,
            paths->path[nbr]->x + screen->x, " ");
    }
    attroff(COLOR_PAIR(4));
    if (nbr_turn == turn)
        return (-turn);
    return (1);
}

void start_display_bonus(lm_tunnel_t **tunnels, path_t *paths)
{
    int input = 0;
    screen_t *screen = malloc(sizeof(screen_t));
    int timeur = 100000;
    int turn = 0;

    initialise_ncurse(screen);
    while (input != ' ') {
        input = getch();
        if (update_camera(input, screen) == 1)
            diplay_node(tunnels, screen, paths, turn);
        if (timeur > 100000) {
            turn += diplay_node(tunnels, screen, paths, turn);
            timeur = 0;
        }
        refresh();
        timeur++;
    }
    end_ncurses();
    free(screen);
}