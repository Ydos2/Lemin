/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "my.h"
#include "main.h"

int main(int ac, char **av)
{
    lm_tunnel_t **tunnels = 0;

    tunnels = build_anthill(av[1]);
    if (!tunnels)
        return (84);
}