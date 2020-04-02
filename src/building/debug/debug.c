/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** debug
*/

#include <stdio.h>
#include "tunnel.h"

void display_links(lm_tunnel_t *tunnel)
{
    if (!tunnel)
        return;
    if (!tunnel->links) {
        printf("%s has no links !\n", tunnel->name);
        return;
    }
    printf("%s is linked to :\n", tunnel->name);
    for (int i = 0; tunnel->links[i]; i++)
        printf("\t- %s\n", tunnel->links[i]->name);
    return;
}

void display_nodes(lm_tunnel_t **anthill)
{
    if (!anthill) {
        printf("Hey there is no anthill!\n");
        return;
    }
    printf("Here are the nodes i found:\n");
    for (int i = 0; anthill[i]; i++)
        printf("\t- %s at %d|%d and its a %s node\n", anthill[i]->name, anthill[i]->x, anthill[i]->y, anthill[i]->type == NORMAL ? "normal" : anthill[i]->type == START ? "start" : "end");
    return;
}