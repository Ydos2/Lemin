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
#include "fae.h"
#include "debug.h"

static void all_star_open(all_star_init_data_t init_data,
    grid_node_t **current, linked_list_t **open_list)
{
    lm_tunnel_t *current_check = 0;
    grid_node_t *tmp = 0;

    for (int y = 0; (*current)->data->links[y]; y++) {
        current_check = (*current)->data->links[y];
        if (!is_blocked(current_check->name, init_data)
            && !(is_open(*open_list, (*current)->data->links[y]))) {
            tmp = open_node(*current, current_check, open_list);
        }
        if (tmp && tmp->data->type == END) {
            *current = tmp;
            return;
        }
    }
}

static int all_star_search(all_star_init_data_t init_data,
    grid_node_t **current, linked_list_t **open_list)
{
    while (1) {
        (debug) ? fae_put("and open ", (*current)->data->name) : 0;
        all_star_open(init_data, current, open_list);
        if ((*current)->data->type == END)
            return 1;
        (*current)->closed = 1;
        *current = get_nearest(*open_list);
        if (!(*current))
            return 0;
        (debug) ? fae_put("\nGo to node %s ", (*current)->data->name) : 0;
    }
}

static path_t launch_all_star(all_star_init_data_t init_data)
{
    linked_list_t *open_list = 0;
    grid_node_t *current = open_node(0, init_data.tunnels[0], &open_list);
    path_t path = {0};
    int result = all_star_search(init_data, &current, &open_list);

    (debug) ? fae_put("\nsearch complete !\n") : 0;
    if (result) {
        (debug) ? fae_put("Way found : ") : 0;
        path = create_path_from_current(current);
    } else {
        (debug) ? fae_put("No way found\n") : 0;
        path.len = -1;
    }
    for (linked_list_t *list = open_list; list; list = list->next) {
        free(list->data);
    }
    list_free_all(&open_list);
    return path;
}

path_t get_new_path(lm_tunnel_t **tunnels, int road_block_size, ...)
{
    char **road_block = malloc(sizeof(char *) * road_block_size);
    va_list list;
    path_t path = {0};

    (debug) ? fae_put("\nLaunch path finding\nsearch roadblocks\n") : 1;
    va_start(list, road_block_size);
    for (int i = 0; i < road_block_size; i++) {
        road_block[i] = va_arg(list, char *);
        (debug) ? fae_put("    node %s\n", road_block[i]) : 0;
    }
    va_end(list);
    set_start(tunnels);
    (debug) ? fae_put("Roadblocks set\nbegin searching\nStart at ") : 1;
    path = launch_all_star(
        (all_star_init_data_t){tunnels, road_block_size, road_block});
    free(road_block);
    return path;
}

path_t get_new_path_srb(lm_tunnel_t **tunnels, int road_block_size,
    char **road_block)
{
    (debug) ? fae_put("Launch path finding\nset roadblocks\n") : 1;
    for (int i = 0; debug && i < road_block_size; i++)
        fae_put("    node %s\n", road_block[i]);
    set_start(tunnels);
    (debug) ? fae_put("Roadblocks set\nbegin searching\nStart at ") : 1;
    return launch_all_star(
        (all_star_init_data_t){tunnels, road_block_size, road_block});
}