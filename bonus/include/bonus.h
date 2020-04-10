/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** bonus
*/

#ifndef BONUS_H_
#define BONUS_H_
#include "main.h"

typedef struct screen_s
{
    int x;
    int y;
} screen_t;

// initialise_ncurses.c
void initialise_ncurse(screen_t *screen);

// start_display_bonus.c
void start_display_bonus(lm_tunnel_t **tunnels, path_t *paths);

// end_ncurses.c
void end_ncurses(void);

#endif /* !BONUS_H_ */