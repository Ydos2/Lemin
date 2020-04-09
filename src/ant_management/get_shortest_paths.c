/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Creates an array of all the shortest paths not crossing each other.
*/

#include "ant_management.h"

path_t *get_shortest_paths(lm_tunnel_t **tunnels)
{
    path_t *paths = NULL;
    int nb_paths = 0;

    nb_paths = get_max_nb_of_paths(tunnels);
    if (nb_paths == 0)
        return (NULL);
    paths = malloc(sizeof(path_t) * (nb_paths + 1));
    if (!paths)
        return (NULL);
    for (int i = 0; i < nb_paths; i++)
        paths[i].len = -1;
    if (find_shortest_paths(tunnels, paths, nb_paths) == 84)
        return (NULL);
    return (paths);
}

int get_max_nb_of_paths(lm_tunnel_t **tunnels)
{
    for (; *tunnels; tunnels++) {
        if ((*tunnels)->type == START)
            return ((*tunnels)->link_nb);
    }
    return (0);
}

int find_shortest_paths(lm_tunnel_t **tunnels, path_t *paths, int nb_paths)
{
    int roadblocks_nb = 0;
    char **roadblocks = NULL;

    for (int i = 0; i < nb_paths; i++) {
        roadblocks = get_roadblocks(&roadblocks_nb, roadblocks, paths[i]);
        if (!roadblocks && i != 0)
            return (84);
        paths[i] = get_new_path_srb(tunnels, roadblocks_nb, roadblocks);
        if (paths[i].len == -1) {
            free(roadblocks);
            return (0);
        }
    }
    free(roadblocks);
    return (0);
}

char **get_roadblocks(int *roadblcks_nb, char **roadblcks, path_t path)
{
    int new_roadblcks_nb = 0;
    char **new_roadblcks = NULL;

    new_roadblcks_nb = path.len - 2;
    if (new_roadblcks_nb <= 0)
        return (roadblcks);
    new_roadblcks = malloc(sizeof(char *) * (*roadblcks_nb + new_roadblcks_nb));
    if (!new_roadblcks) {
        if (roadblcks)
            free(roadblcks);
        return (NULL);
    }
    for (int i = 0; i < *roadblcks_nb; i++)
        new_roadblcks[i] = roadblcks[i];
    for (int i = 0; i < new_roadblcks_nb; i++)
        new_roadblcks[*roadblcks_nb + i] = ((path.path)[i + 1])->name;
    if (roadblcks)
        free(roadblcks);
    (*roadblcks_nb) += new_roadblcks_nb;
    return (new_roadblcks);
}

void free_paths(path_t *paths)
{
    for (int i = 0; paths[i].len != -1; i++)
        free(paths[i].path);
    free(paths);
}