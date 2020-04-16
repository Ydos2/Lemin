/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** build_anthill
*/

#ifndef BUILD_ANTHILL_H_
#define BUILD_ANTHILL_H_

#include "vector2.h"
#include "tunnel.h"

lm_tunnel_t *search_node(char *name, lm_tunnel_t **anthill);
char *get_user_entry(char *old_entry, char ***tunnels_stdin);
void add_tunnel(lm_tunnel_t ***tunnel, vector2_t pos, char *name, int nb);
void link_nodes(lm_tunnel_t *first, lm_tunnel_t *second);
int get_command(char *cmd, int actual_type);

//debug
void debug_anthill(lm_tunnel_t **anthill);

#endif /* !BUILD_ANTHILL_H_ */