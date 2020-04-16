/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** display : header
*/

#ifndef DEF_DISPLAY_H
#define DEF_DISPLAY_H

#include "tunnel.h"
#include "path.h"

// display.c
int is_digit(char c);
void display_infos_stdout(int nb_of_ants, lm_tunnel_t **tunnels, char **t);

// dislay_movements_stdout.c
void display_movements_stdout(path_t *paths, int *ants_per_path, int nb_ants);

#endif // DEF_DISPLAY_H