/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include "tunnel.h"

lm_tunnel_t **build_anthill(char *filepath, int *nb_ants, int debug);
path_t *get_shortest_paths(lm_tunnel_t **tunnels);
void display_ants_movements(path_t *paths, int nb_of_ants);

#endif /* !MAIN_H_ */
