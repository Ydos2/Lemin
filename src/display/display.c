/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** Display of results.
*/

#include <stddef.h>
#include "fae.h"
#include "display.h"

static lm_tunnel_t *get_room_by_id(lm_tunnel_t **tunnels, int id)
{
    for (int i = 0; tunnels[i]; i++){
        if ((tunnels[i])->tunnel_id == id)
            return (tunnels[i]);
    }
    return (NULL);
}

static void display_rooms(lm_tunnel_t **tunnels)
{
    lm_tunnel_t *tunnel = NULL;
    int tunnels_nb = 0;

    fae_put("#rooms\n");
    for (; tunnels[tunnels_nb]; tunnels_nb++);
    for (int i = 0; i < tunnels_nb; i++) {
        tunnel = get_room_by_id(tunnels, i);
        if (tunnel->type == START)
            fae_put("##start\n");
        else if (tunnel->type == END)
            fae_put("##end\n");
        fae_put("%s %d %d\n", tunnel->name, tunnel->x, tunnel->y);
    }
}

static void display_tunnels(lm_tunnel_t **tunnels)
{
    fae_put("#tunnels\n");
    // add every tunnel
}

void display_infos_anthill_stdout(int nb_of_ants, lm_tunnel_t **tunnels)
{
    fae_put("#number_of_ants\n%d\n", nb_of_ants);
    display_rooms(tunnels);
    display_tunnels(tunnels);
}

void display_movements_stdout(int *ants_per_path, int nb_of_ants)
{
    fae_put("#moves\n");
    // add moves
}