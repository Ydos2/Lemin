/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** paths
*/

#ifndef PATH_H_
#define PATH_H_

typedef struct path {
    lm_tunnel_t **path;
    int len;
} path_t;

path_t get_new_path(lm_tunnel_t **tunnels, int road_block, ...);

#endif /* !PATH_H_ */