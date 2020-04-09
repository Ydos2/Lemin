/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** all star
*/

#ifndef ALL_STAR_H_
#define ALL_STAR_H_

#include "tunnel.h"
#include "vector2.h"
#include "linked_list.h"
#include "path.h"

typedef struct all_star_init_data {
    lm_tunnel_t **tunnels;
    int rb_size;
    char **rb;
} all_star_init_data_t;

typedef struct grid_node {
    int distance;
    int closed;
    lm_tunnel_t *data;
    struct grid_node *parent;
} grid_node_t;

//utils
void set_start(lm_tunnel_t **tunnels);
int is_blocked(char *node, all_star_init_data_t init_data);
int is_open(linked_list_t *open_list, lm_tunnel_t *tunnel);
grid_node_t *get_nearest(linked_list_t *open_list);

//node
grid_node_t *open_node(grid_node_t *parent, lm_tunnel_t *current,
    linked_list_t **open_list);

//path
path_t create_path_from_current(grid_node_t *current);

//debug
void display_path(path_t path);

#endif /* !ALL_STAR_H_ */