/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include "my.h"
#include "main.h"
#include "path.h"
#include "ant_management.h"
#include "display.h"
#include "bonus.h"

static void draw_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./lem_in < anthill\n", 20);
}

static int start_lemin(char **av, int debug)
{
    lm_tunnel_t **tunnels = 0;
    path_t *paths = NULL;
    int nb_ants = 0;

    initialise_ncurse();
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
    start_display_bonus(tunnels, paths);
    free_paths(paths);
    return (0);
}

int main(int ac, char **av)
{
    int debug = 0;
    int bonus = 0;

    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            draw_help();
            return (0);
        }
        if (my_strcmp(av[1], "-d") == 0)
            debug = 1;
        if (debug == 1)
            ac = 1;
    }
    if (ac != 1)
        return (84);
    return (start_lemin(av, debug));
}