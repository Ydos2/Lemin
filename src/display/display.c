/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Display of results.
*/

#include <stddef.h>
#include <unistd.h>
#include "fae.h"
#include "display.h"

static lm_tunnel_t *get_room_by_id(lm_tunnel_t **tunnels, int id)
{
    for (int i = 0; tunnels[i]; i++){
        if ((tunnels[i])->tunnel_id == id)
            return (tunnels[i]);
    }
    return (NULL);
}

static void display_rooms_and_tunnels(lm_tunnel_t **tunnels, char **t)
{
    lm_tunnel_t *tunnel = NULL;
    int len = 0;

    for (; tunnels[len]; len++);
    for (int i = 0; i < len; i++) {
        tunnel = get_room_by_id(tunnels, i);
        if (tunnel->type == START)
            fae_put("##start\n");
        else if (tunnel->type == END)
            fae_put("##end\n");
        fae_put("%s %d %d\n", tunnel->name, tunnel->x, tunnel->y);
    }
    fae_put("#tunnels\n");
    for (int i = 0; t[i]; i++) {
        if (t[i][0] == '#')
            continue;
        for (len = 0; t[i][len] == '-' || is_digit(t[i][len]); len++);
        write(1, t[i], len);
        write(1, "\n", 1);
    }
}

int is_digit(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}

void display_infos_stdout(int nb_of_ants, lm_tunnel_t **tunnels, char **t)
{
    fae_put("#number_of_ants\n%d\n", nb_of_ants);
    for (int i = 0; *t; t++, i = 0) {
        if (!is_digit((*t)[i]))
            continue;
        for (; is_digit((*t)[i]); i++);
        if ((*t)[i] != '-')
            continue;
        i++;
        if (!is_digit((*t)[i]))
            continue;
        for (; is_digit((*t)[i]); i++);
        if ((*t)[i] != 0)
            continue;
        break;
    }
    fae_put("#rooms\n");
    display_rooms_and_tunnels(tunnels, t);
}