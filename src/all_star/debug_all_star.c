/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** debug
*/

#include "all_star.h"
#include "path.h"
#include "fae.h"

void display_path(path_t path)
{
    for (int i = 0; i < path.len; i++) {
        fae_put("%s", path.path[i]->name);
        if (i + 1 == path.len)
            fae_put("\n");
        else
            fae_put(" => ");
    }
}
