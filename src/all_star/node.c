/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** debug
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

static grid_node_t *new_node(lm_tunnel_t *data,
    struct grid_node *parent, int distance)
{
    grid_node_t *nn = malloc(sizeof(grid_node_t));

    nn->data = data;
    nn->parent = parent;
    nn->distance = distance;
    nn->closed = 0;
    return nn;
}

grid_node_t *open_node(grid_node_t *parent, lm_tunnel_t *current,
    linked_list_t **open_list)
{
    grid_node_t *gcurrent = 0;

    if (parent)
        gcurrent = new_node(current, parent, parent->distance + 1);
    else
        gcurrent = new_node(current, NULL, 0);
    list_add_begin(open_list, gcurrent);
    if (debug)
        fae_put("%s ", current->name);
    return gcurrent;
}