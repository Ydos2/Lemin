/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Error management
*/

#include "tunnel.h"

int detect_errors(lm_tunnel_t **tunnels)
{
    int starts_found = 0;
    int ends_found = 0;

    for (int i = 0; tunnels[i]; i++) {
        starts_found += (tunnels[i]->type == START);
        ends_found += (tunnels[i]->type == END);
        if (starts_found > 1 || ends_found > 1)
            return (1);
    }
    return (0);
}