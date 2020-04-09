/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** tunnel
*/

#ifndef TUNNEL_H_
#define TUNNEL_H_

typedef enum lm_tunnel_type {
    ERROR = 0,
    NORMAL = 1,
    START = 2,
    END = 3,
    CHECK = 4,
} lm_tunnel_type;

typedef struct lm_tunnel_s {
    int tunnel_id;
    char *name;
    int x;
    int y;
    lm_tunnel_type type;
    int link_nb;
    struct lm_tunnel_s **links;
} lm_tunnel_t;

#endif /* !TUNNEL_H_ */