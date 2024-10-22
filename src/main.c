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

static void draw_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./lem_in < anthill\n", 20);
}

static int start_lemin(char **av, int debug)
{
    lm_tunnel_t **tunnels = 0;
    path_t *paths = NULL;
    char **tunnels_stdin = NULL;
    int nb_ants = 0;

    tunnels = build_anthill(av[1], &nb_ants, &tunnels_stdin, debug);
    if (!tunnels || detect_errors(tunnels))
        return (84);
    paths = get_shortest_paths(tunnels);
    if (!paths || !get_new_path_srb(tunnels, 0, NULL).path)
        return (84);
    display_infos_stdout(nb_ants, tunnels, tunnels_stdin);
    if (display_ants_movements(paths, nb_ants) == 84) {
        free_paths(paths);
        return (84);
    }
    free_paths(paths);
    return (0);
}

int main(int ac, char **av)
{
    int debug = 0;

    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            draw_help();
            return (0);
        } else if (my_strcmp(av[1], "-d") == 0) {
            debug = 1;
            ac = 1;
        }
    }
    if (ac != 1)
        return (84);
    return (start_lemin(av, debug));
}