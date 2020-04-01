/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include "tunnel.h"
#include "my.h"

int main(int ac, char **av)
{
    lm_tunnel_t *tunnels = 0;

    if (ac != 2) {
        my_put_error("File needed !\n");
        return (84);
    }
    tunnels = build_anthill(av[1]);
    if (!tunnels)
        return (84);
}