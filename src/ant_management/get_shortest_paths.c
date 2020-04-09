/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Creates an array of all the shortest paths not crossing each other.
*/

#include "tunnel.h"

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
    vector2s_t *roadblocks = NULL;

    for (int i = 0; i < nb_paths; i++) {
        roadblocks = add_roadblocks(&roadblocks_nb, roadblocks, paths, i);
        if (!roadblocks)
            return (84);
        paths[i] = get_new_path_srb(tunnels, roadblocks_nb, roadblocks);
        if (paths[i].len == -1) {
            free(roadblocks);
            return (0);
        }
    }
    return (0);
}

vector2s_t *add_roadblocks(int *rbk_nb, vector2s_t *rbk, path_t *paths, i_path)
{
    vector2s_t *new_rbk = NULL;
    int new_rbk_nb = 0;

    for (int i = 0; paths[i_path].path[i]; i++)
        new_rbk_nb++;
    new_rbk = malloc(sizeof(vector2s_t) * (*rbk_nb + new_rbk_nb));
    if (!new_rbk)
        return (NULL);

    // TODO : finish

    for (int i = 0; paths[i].len != -1; i++) {
        for (int j = 0; paths[i].path[j]; j++)
            (*rbk_nb)++;
    }



    return (new_rbk);
}

void free_paths(path_t *paths)
{
    for (int i = 0; paths[i].len != -1; i++)
        free(paths[i].path);
    free(paths);
}