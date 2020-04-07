/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "main.h"
#include "path.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    lm_tunnel_t **tunnels = 0;
    path_t p = {0};

    tunnels = build_anthill(av[1]);
    if (!tunnels)
        return (84);
    p = get_new_path(tunnels, 0);
    free(p.path);
    p = get_new_path(tunnels, 1, "15", "6");
    free(p.path);
}