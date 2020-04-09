/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** debug
*/

#include <stdio.h>
#include "tunnel.h"
#include "fae.h"
#include "debug.h"

static void display_links(lm_tunnel_t *tunnel)
{
    if (!tunnel)
        return;
    if (!tunnel->links) {
        fae_put("%s has no links !\n", tunnel->name);
        return;
    }
    fae_put("%s is linked to :\n", tunnel->name);
    for (int i = 0; tunnel->links[i]; i++)
        fae_put("\t- %s\n", tunnel->links[i]->name);
    return;
}

static void display_nodes(lm_tunnel_t **anthill)
{
    if (!anthill) {
        fae_put("Hey there is no anthill!\n");
        return;
    }
    fae_put("Here are the nodes i found:\n");
    for (int i = 0; anthill[i]; i++)
        fae_put("\t- %s at %d|%d and its a %s node\n", anthill[i]->name,
            anthill[i]->x, anthill[i]->y, anthill[i]->type == NORMAL ?
                "normal" : anthill[i]->type == START ? "start" : "end");
    return;
}

void debug_anthill(lm_tunnel_t **anthill)
{
    display_nodes(anthill);
    fae_put("\n");
}