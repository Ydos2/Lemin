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
            screen->x--;
            break;
        case KEY_RIGHT:
            screen->x++;
            break;
        case KEY_UP:
            screen->y--;
            break;
        case KEY_DOWN:
            screen->y++;
            break;
        default:
            return (0);
    }
    clear();
    printw("X coord : %d\nY coord : %d", screen->x, screen->y);
    return (1);
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
    attron(COLOR_PAIR(3));
    for (int nbr = 0; tunnels[nbr] != NULL; nbr++) {
        mvprintw(tunnels[nbr]->y + screen->y,
            tunnels[nbr]->x + screen->x, " ");
    }
    attroff(COLOR_PAIR(3));
    display_start_end(paths->len, paths, screen);
    if (paths->len - 1 <= turn)
        return (-1);
    attron(COLOR_PAIR(4));
    for (int nbr = 0; nbr <= turn; nbr++) {
        mvprintw(paths->path[nbr]->y + screen->y,
            paths->path[nbr]->x + screen->x, " ");
    }
    attroff(COLOR_PAIR(4));
    return (1);
}

static int loop_node(lm_tunnel_t **tunnels, path_t *paths,
    screen_t *screen, int turn)
{
    if (diplay_node(tunnels, screen, paths, turn) == -1)
        turn = 0;
    else
        turn++;
    return (turn);
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
            turn = loop_node(tunnels, paths, screen, turn);
            timeur = 0;
        }
        refresh();
        timeur++;
    }
    end_ncurses();
    free(screen);
}