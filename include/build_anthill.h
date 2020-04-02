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
char *get_user_entry(char *old_entry);
void add_tunnel(lm_tunnel_t ***tunnel, vector2_t pos, char *name, int nb);
void link_nodes(lm_tunnel_t *first, lm_tunnel_t *second);

#endif /* !BUILD_ANTHILL_H_ */