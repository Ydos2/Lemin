/*
** EPITECH PROJECT, 2020
** src_tests_initialisation
** File description:
** src_tests_initialisation
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "build_anthill.h"
#include "vector2.h"
#include "tunnel.h"
#include "debug.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (build_tunnels, anthill_test, .init = redirect_all_std)
{
    lm_tunnel_t **anthill = NULL;
    
    anthill = build_tunnels();
    cr_assert_eq(anthill[0]->x, 0);
}