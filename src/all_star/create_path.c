/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** create path
*/

#include <stdlib.h>
#include <stdarg.h>
#include "all_star.h"
#include "tunnel.h"
#include "vector2.h"
#include "path.h"
#include "linked_list.h"
#include "fae.h"
#include "debug.h"

path_t create_path_from_current(grid_node_t *current)
{
    path_t path = {0, 0};

    path.len = current->distance + 1;
    path.path = malloc(sizeof(lm_tunnel_t *) * path.len);

    for (int i = path.len - 1; i >= 0; i--) {
        path.path[i] = current->data;
        current = current->parent;
    }
    (debug) ? display_path(path) : 0;
    return path;
}