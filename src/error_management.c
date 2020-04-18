/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Error management
*/

#include "tunnel.h"
#include "my.h"

static int check_end_and_start(lm_tunnel_t **tunnels)
{
    int starts_found = 0;
    int ends_found = 0;

    for (int i = 0; tunnels[i]; i++) {
        starts_found += (tunnels[i]->type == START);
        ends_found += (tunnels[i]->type == END);
    }
    if (starts_found != 1 || ends_found != 1)
        return (84);
    return (0);
}

static int is_unique_name(lm_tunnel_t **tunnels, int start)
{
    for (int j = start + 1; tunnels[j]; j++) {
        if (my_strcmp(tunnels[start]->name, tunnels[j]->name) == 0)
            return (0);
    }
    return (1);
}

static int check_names(lm_tunnel_t **tunnels)
{
    for (int i = 0; tunnels[i + 1]; i++) {
        if (!is_unique_name(tunnels, i))
            return (84);
    }
    return (0);
}

int detect_errors(lm_tunnel_t **tunnels)
{
    if (check_end_and_start(tunnels) == 84)
        return (84);
    if (check_names(tunnels) == 84)
        return (84);
    return (0);
}