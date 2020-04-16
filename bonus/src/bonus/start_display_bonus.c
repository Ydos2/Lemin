/*
** EPITECH PROJECT, 2020
** start_display_bonus
** File description:
** start_display_bonus
*/

#include <ncurses.h>
#include <stdlib.h>
#include "main.h"
#include "bonus.h"

static int update_camera(int input, screen_t *screen)
{
    switch (input) {
        case KEY_LEFT:
            clear();
            screen->x--;
            printw("X coord : %d\nY coord : %d", screen->x, screen->y);
            return (1);
        case KEY_RIGHT:
            clear();
            screen->x++;
            printw("X coord : %d\nY coord : %d", screen->x, screen->y);
            return (1);
        case KEY_UP:
            clear();
            screen->y--;
            printw("X coord : %d\nY coord : %d", screen->x, screen->y);
            return (1);
        case KEY_DOWN:
            clear();
            screen->y++;
            printw("X coord : %d\nY coord : %d", screen->x, screen->y);
            return (1);
    }
    return (0);
}

static void display_start_end(int nbr_turn, path_t *paths,
    screen_t *screen)
{
    attron(COLOR_PAIR(8));
    mvprintw(paths->path[0]->y + screen->y,
            paths->path[0]->x + screen->x, " ");
    attroff(COLOR_PAIR(8));
    attron(COLOR_PAIR(6));
    mvprintw(paths->path[nbr_turn - 1]->y + screen->y,
            paths->path[nbr_turn - 1]->x + screen->x, " ");
    attroff(COLOR_PAIR(6));
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
    attroff(COLOR_PAIR(3));/*
    for (; paths->path[nbr_turn] != NULL; nbr_turn++);
    display_start_end(nbr_turn, paths, screen);
    if (nbr_turn <= turn)
        return (-1);
    attron(COLOR_PAIR(4));
    for (int nbr = 0; nbr <= turn; nbr++) {
        mvprintw(paths->path[nbr]->y + screen->y,
            paths->path[nbr]->x + screen->x, " ");
    }
    attroff(COLOR_PAIR(4));*/
    return (1);
}

void start_display_bonus(lm_tunnel_t **tunnels, path_t *paths)
{
    int input = 0;
    screen_t *screen = malloc(sizeof(screen_t));
    int timeur = 100000;
    int turn = 0;

    initialise_ncurse(screen);
    printw("X coord : %d\nY coord : %d", screen->x, screen->y);
    while (input != ' ') {
        input = getch();
        if (update_camera(input, screen) == 1)
            diplay_node(tunnels, screen, paths, turn);
        if (timeur > 100000) {
            if (diplay_node(tunnels, screen, paths, turn) == -1)
                turn = 0;
            else
                turn++;
            timeur = 0;
        }
        refresh();
        timeur++;
    }
    end_ncurses();
    free(screen);
}