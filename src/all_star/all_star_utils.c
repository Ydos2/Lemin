/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** all star utils
*/

#include <stdlib.h>
#include <stdarg.h>
#include "all_star.h"
#include "tunnel.h"
#include "vector2.h"
#include "path.h"
#include "linked_list.h"
#include "debug.h"
#include "fae.h"

void set_start(lm_tunnel_t **tunnels)
{
    lm_tunnel_t *tmp = 0;

    if (tunnels[0]->type == START)
        return;
    for (int i = 0; tunnels[i]; i++) {
        if (tunnels[i]->type == START) {
            tmp = tunnels[0];
            tunnels[0] = tunnels[i];
            tunnels[i] = tmp;
            return;
        }
    }
    return;
}

int is_blocked(char *node, all_star_init_data_t init_data)
{
    for (int i = 0; i < init_data.rb_size; i++) {
        if (!fae_strcmp(node, init_data.rb[i]))
            return 1;
    }
    return 0;
}

int is_open(linked_list_t *open_list, lm_tunnel_t *tunnel)
{
    for (linked_list_t *list = open_list; list; list = list->next) {
        if (((grid_node_t *)(list->data))->data == tunnel) {
            return 1;
        }
    }
    return 0;
}

grid_node_t *get_nearest(linked_list_t *open_list)
{
    grid_node_t *gn = (grid_node_t *)(open_list->data);

    for (linked_list_t *list = open_list; list; list = list->next)
        if ((((grid_node_t *)(list->data))->distance < gn->distance
            && !((grid_node_t *)(list->data))->closed) || gn->closed)
            gn = (grid_node_t *)(list->data);
    if (gn->closed)
        return NULL;
    return gn;
}