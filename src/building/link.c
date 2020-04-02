/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** link
*/

#include "tunnel.h"
#include "link.h"

void link_nodes(lm_tunnel_t *first, lm_tunnel_t *second)
{
    first->link_nb++;
    second->link_nb++;
    first->links = add_space(first->links, first->link_nb);
    second->links = add_space(second->links, second->link_nb);
    first->links[first->link_nb - 1] = second;
    second->links[second->link_nb - 1] = first;
}