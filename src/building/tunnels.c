/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** tunnels
*/

#include "tunnel.h"
#include "my.h"

static int has_char(char *str, char c)
{
    int i = 0;

    for (; str[i] && str[i] != c; i++);
    return (str[i] == c);
}

/* //UNFINISHED\\ */

int get_tunnels(char **file, lm_tunnel_t **tunnels)
{
    int line = 0;

    while (file[line] && !has_char(file[line], '-')) {

    }
}

int count_tunnels(char **file)
{
    int tunnels = 0;

    for (int i = 0; file[i] && !has_char(file[i], '-'); )
        if (file[i][0] == '#')
            tunnels++;
    return (tunnels);
}

void add_tunnel(lm_tunnel_t *tunnel, int x, int y, char *name)
{
    tunnel->x = x;
    tunnel->y = y;
    tunnel->name = name;
    tunnel->links = 0;
}