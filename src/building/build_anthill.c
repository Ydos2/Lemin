/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** build_anthill
*/

#include <stdlib.h>
#include "vector2.h"
#include "tunnel.h"
#include "my.h"

int get_command(char *cmd, int actual_type)
{
    static int has_end = 0;
    static int has_start = 0;

    if (actual_type == CHECK)
        return (has_end == 1 && has_start == 1);
    if (my_strcmp(cmd, "start")) {
        has_start++;
        return (START);
    }
    if (my_strcmp(cmd, "end")) {
        has_end++;
        return (END);
    }
    return (actual_type);
}

int is_valid_tunnel(char *str, lm_tunnel_t *tunnel, int type)
{
    char *name = NULL;
    vector2_t vect;
    int pos = 0;

    pos = my_strjump(str, ' ');
    if (!str[pos] || str[0] == '#')
        return (0);
    name = malloc(sizeof(char) * pos + 1);
    name = my_strncpy(name, str, pos);
    vect.x = my_getnbr(str + pos + 1);
    pos += my_strjump(str + pos, ' ');
    if (!str[pos])
        return (0);
    vect.y = my_getnbr(str + pos + 1);
    pos += my_strjump(str + pos, ' ');
    if (str[pos] != 0 && str[pos] != '\n')
        free(name);
    add_tunnel(tunnel, vect.x, vect.y, name);
    return (1);
}

lm_tunnel_t **build_tunnels(char **file)
{
    lm_tunnel_t **new = NULL;
    int i = 0;
    int next_type = NORMAL;
    int size = count_tunnels(file + 1);

    if (size < 2)
        return (NULL);
    new = malloc(sizeof(lm_tunnel_t *) * (count_tunnels(file + 1) + 1));
    for (int x = 1; x != size; x++) {
        if (file[x][0] == '#' && file[x][1] == '#')
            next_type = get_command(file[x] + 2, next_type);
        else if (is_valid_tunnel(file[x], new[i], next_type)) {
            new[i]->type = next_type;
            next_type = NORMAL;
            i++;
        }
    }
    new[i] = NULL;
    return (new);
}

lm_tunnel_t **build_anthill(char *filepath)
{
    char **file = read_file(filepath);
    int ant = 0;
    lm_tunnel_t **anthill = NULL;
    int link_position = 0;

    if (!file)
        return (NULL);
    allocate_anthill(file);
    ant = my_getnbr(file[0]);
    if (ant <= 0 || !file)
        return (NULL);
    link_position = get_tunnels(file + 1, anthill);
    link_tunnels(file + link_position, anthill);
}