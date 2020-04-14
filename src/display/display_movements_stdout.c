/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Displays the movements of the ants.
*/

#include <unistd.h>
#include "fae.h"
#include "display.h"

void display_movements_stdout(path_t *paths, int *ants_per_path, int nb_ants)
{
    int nb_paths = 0;
    int ants_in_end = 0;
    lm_tunnel_t *node = NULL;

    for (; ants_per_path[nb_paths] > 0; nb_paths++);
    for (int laps = 0, is_lap = 0; ants_in_end < nb_ants; laps++, is_lap = 0) {
        for (int ant = 0, index_in_path = 0; ant < nb_ants; ant++) {
            index_in_path = laps - (ant / nb_paths + 1);
            if (index_in_path < 0 || index_in_path >= paths[ant % nb_paths].len)
                continue;
            node = paths[ant % nb_paths].path[index_in_path];
            if (node->type != START)
                fae_put("P%d-%s ", ant + 1, node->name);
            if (node->type == END)
                ants_in_end++;
            is_lap = is_lap ? 1 : (node->type != START);
        }
        if (is_lap)
            write(1, "\n", 1);
    }
}