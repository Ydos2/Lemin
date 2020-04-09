/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** paths
*/

#ifndef PATH_H_
#define PATH_H_

#include "vector2.h"
#include "tunnel.h"

typedef struct path {
    lm_tunnel_t **path;
    int len;
} path_t;

path_t get_new_path(lm_tunnel_t **tunnels, int road_block, ...);
path_t get_new_path_srb(lm_tunnel_t **tunnels, int road_block_size,
    char **road_block);

#endif /* !PATH_H_ */