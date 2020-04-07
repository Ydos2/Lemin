/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** tunnels
*/

#include <stdlib.h>
#include "vector2.h"
#include "tunnel.h"
#include "my.h"

static int has_char(char *str, char c)
{
    int i = 0;

    for (; str[i] && str[i] != c; i++);
    return (str[i] == c);
}

lm_tunnel_t *search_node(char *name, lm_tunnel_t **list)
{
    int i = 0;

    for (; list[i] != NULL && my_strcmp(name, list[i]->name) != 0; i++);;
    return (list[i]);
}

lm_tunnel_t **add_space(lm_tunnel_t **tunnel, int nb)
{
    lm_tunnel_t **new = malloc(sizeof(lm_tunnel_t *) * (nb + 1));

    if (tunnel == NULL) {
        new[nb - 1] = malloc(sizeof(lm_tunnel_t));
        new[nb] = 0;
        return (new);
    }
    for (int i = 0; i != nb; i++)
        new[i] = tunnel[i];
    new[nb - 1] = malloc(sizeof(lm_tunnel_t));
    new[nb] = NULL;
    free(tunnel);
    return (new);
}

void add_tunnel(lm_tunnel_t ***tunnel, vector2_t pos, char *name, int nb)
{
    lm_tunnel_t **lm_tunnel;

    my_strlen(name);
    *tunnel = add_space(*tunnel, nb);
    lm_tunnel = *tunnel;
    lm_tunnel[nb - 1]->x = pos.x;
    lm_tunnel[nb - 1]->y = pos.y;
    lm_tunnel[nb - 1]->name = my_strdup(name);
    lm_tunnel[nb - 1]->link_nb = 0;
    lm_tunnel[nb - 1]->links = 0;
    my_strlen(name);
}