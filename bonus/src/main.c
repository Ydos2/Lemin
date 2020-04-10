/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "main.h"
#include "path.h"
#include "ant_management.h"
#include "display.h"
#include "bonus.h"

static void draw_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./lem_in_bonus anthill\n", 24);
}

static int start_lemin(char **av, int debug)
{
    lm_tunnel_t **tunnels = 0;
    path_t *paths = NULL;
    int nb_ants = 0;
    int old_stdout = dup(0);
    FILE *fp1 = freopen(av[1], "r", stdin);
    FILE *fp2 = fdopen(old_stdout, "w");

    freopen(av[1], "r", stdin);
    tunnels = build_anthill(av[1], &nb_ants, debug);
    if (!tunnels)
        return (84);
    paths = get_shortest_paths(tunnels);
    if (!paths)
        return (84);
    display_infos_anthill_stdout(nb_ants, tunnels);
    if (display_ants_movements(paths, nb_ants) == 84) {
        free_paths(paths);
        return (84);
    }
    fclose(stdin);
    *stdin = *fp2;
    start_display_bonus(tunnels, paths);
    free_paths(paths);
    return (0);
}

int main(int ac, char **av)
{
    int debug = 0;

    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
        draw_help();
        return (0);
    }
    return (start_lemin(av, debug));
}