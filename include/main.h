/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include "tunnel.h"
#include "path.h"

lm_tunnel_t **build_anthill(char *filepath, int *nb_ants, int debug);
path_t *get_shortest_paths(lm_tunnel_t **tunnels);
void display_infos_anthill_stdout(int nb_ants, lm_tunnel_t **tunnels);
int display_ants_movements(path_t *paths, int nb_of_ants);
void free_paths(path_t *paths);

#endif /* !MAIN_H_ */
