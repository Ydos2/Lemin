/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Decides, at evey lap, which paths will be taken by an ant.
*/

#include "ant_management.h"

int display_ants_movements(path_t *paths, int nb_of_ants)
{
    int *ants_per_path = NULL;

    ants_per_path = get_ants_per_path(paths, nb_of_ants);
    if (!ants_per_path)
        return (84);
    fae_put("#moves\n");
    display_movements_stdout(ants_per_path, nb_of_ants);
    free(ants_per_path);
    return (0);
}

int *get_ants_per_path(path_t *paths, int nb_of_ants)
{
    int *ants_per_path = NULL;
    int nb_of_paths = 0;

    ants_per_path = get_default_distribution(paths, nb_of_ants, &nb_of_paths);
    if (!ants_per_path)
        return (NULL);
    for (int i = 1; nb_of_paths > 1; i = (i + 1 >= nb_of_paths) ? 1 : i + 1) {
        if (is_current_path_worth_it(ants_per_path, paths, i)) {
            (ants_per_path[i])++;
            (ants_per_path[0])--;
        } else
            nb_of_paths = i;
    }
    return (ants_per_path);
}

int *get_default_distribution(path_t *paths, int nb_ants, int *nb_paths)
{
    int *ants_per_path = NULL;

    for (; paths[*nb_paths].len != -1; (*nb_paths)++);
    ants_per_path = malloc(sizeof(int) * (*nb_paths + 1));
    if (!ants_per_path)
        return (NULL);
    ants_per_path[*nb_paths] = -1;
    ants_per_path[0] = nb_ants;
    for (int i = 1; i < *nb_paths; i++)
        ants_per_path[i] = 0;
    return (ants_per_path);
}

int is_current_path_worth_it(int *ants_per_path, path_t *paths, int path_index)
{
    int lapses_before = 0;
    int lapses_after = 0;

    lapses_before = get_total_lapses(ants_per_path, paths);
    (ants_per_path[path_index])++;
    (ants_per_path[0])--;
    lapses_after = get_total_lapses(ants_per_path, paths);
    (ants_per_path[path_index])--;
    (ants_per_path[0])++;
    if (lapses_before > lapses_after)
        return (1);
    return (0);
}

int get_total_lapses(int *ants_per_path, path_t *paths)
{
    int max_lapses = 0;
    int lapses = 0;

    for (int i = 0; ants_per_path[i] != -1; i++) {
        lapses = paths[i].len + ants_per_path[i];
        if (lapses > max_lapses)
            max_lapses = lapses;
    }
    return (max_lapses);
}