/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** ant_management : header
*/

#ifndef DEF_ANT_MANAGEMENT_H_
#define DEF_ANT_MANAGEMENT_H_

#include <stdlib.h>
#include "fae.h"
#include "tunnel.h"
#include "path.h"
#include "display.h"

// get_shortest_path.c
path_t *get_shortest_paths(lm_tunnel_t **tunnels);
int get_max_nb_of_paths(lm_tunnel_t **tunnels);
int find_shortest_paths(lm_tunnel_t **tunnels, path_t *paths, int nb_paths);
char **get_roadblocks(int *roadblcks_nb, char **roadblcks, path_t path);
void free_paths(path_t *paths);

// ants_movements.c
int display_ants_movements(path_t *paths, int nb_of_ants);
int *get_ants_per_path(path_t *paths, int nb_of_ants);
int *get_default_distribution(path_t *paths, int nb_ants, int *nb_paths);
int is_current_path_worth_it(int *ants_per_path, path_t *paths, int path_index);
int get_total_lapses(int *ants_per_path, path_t *paths);

#endif // DEF_ANT_MANAGEMENT_H_