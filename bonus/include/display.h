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

void display_infos_anthill_stdout(int nb_ants, lm_tunnel_t **tunnels);
void display_movements_stdout(int *ants_per_path, int nb_of_ants);

#endif // DEF_DISPLAY_H