/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** build_anthill
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "build_anthill.h"
#include "vector2.h"
#include "tunnel.h"
#include "debug.h"
#include "my.h"

int get_command(char *cmd, int actual_type)
{
    static int has_end = 0;
    static int has_start = 0;

    if (actual_type == CHECK)
        return (has_end == 1 && has_start == 1);
    if (my_strcmp(cmd, "start") == 0) {
        has_start++;
        return (START);
    }
    if (my_strcmp(cmd, "end") == 0) {
        has_end++;
        return (END);
    }
    return (actual_type);
}

int is_valid_tunnel(char *str, lm_tunnel_t ***tunnel, int type, int tunnel_nb)
{
    char *name = NULL;
    vector2_t vect;
    int pos = 0;

    pos = my_strjump(str, ' ') + 1;
    if (!str[pos - 1] || !str[pos] || str[0] == '#')
        return (0);
    name = my_strndup(str, pos - 1);
    vect.x = my_getnbr(str + pos);
    if (str[pos] == '-')
        return (0);
    pos += my_strjump(str + pos, ' ') + 1;
    if (!str[pos - 1] || !str[pos])
        return (0);
    vect.y = my_getnbr(str + pos);
    pos += my_strjump(str + pos, ' ');
    if (str[pos] != 0)
        free(name);
    add_tunnel(tunnel, vect, name, tunnel_nb);
    return (1);
}

void is_linker(char *entry, lm_tunnel_t **anthill)
{
    char *first;
    lm_tunnel_t *f_node = NULL;
    lm_tunnel_t *s_node = NULL;
    int pos = 0;

    if (!anthill)
        return;
    first = my_strndup(entry, my_strjump(entry, '-'));
    f_node = search_node(first, anthill);
    free(first);
    if (entry[my_strjump(entry, '-')] == '\0')
        return;
    s_node = search_node(entry + my_strjump(entry, '-') + 1, anthill);
    if (!s_node || !f_node)
        return;
    link_nodes(f_node, s_node);
}

lm_tunnel_t **build_tunnels(void)
{
    lm_tunnel_t **anthill = NULL;
    char *user_entry = NULL;
    int tunnel_nb = 0;
    int tunnel_type = NORMAL;

    while (1) {
        user_entry = get_user_entry(user_entry);
        if (!user_entry)
            break;
        if (is_valid_tunnel(user_entry, &anthill, tunnel_type, tunnel_nb + 1)) {
            anthill[tunnel_nb]->type = tunnel_type;
            tunnel_type = NORMAL;
            tunnel_nb++;
        } else if (user_entry[0] == '#' && user_entry[1] == '#')
            tunnel_type = get_command(user_entry + 2, tunnel_type);
        else
            is_linker(user_entry, anthill);
    }
    return (anthill);
}

lm_tunnel_t **build_anthill(char *filepath, int debug)
{
    char *user_entry = NULL;
    int ant = 0;
    lm_tunnel_t **anthill = NULL;
    int link_position = 0;

    user_entry = get_user_entry(user_entry);
    ant = my_getnbr(user_entry);
    if (!user_entry || ant <= 0)
        return (NULL);
    anthill = build_tunnels();
    if (debug == 1)
        debug_anthill(anthill);
    return (anthill);
}