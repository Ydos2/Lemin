/*
** EPITECH PROJECT, 2020
** lib_tests_compute
** File description:
** lib_tests_compute
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_compute_power_rec, compute_power, .init = redirect_all_std)
{
    int rtn = 0;

    rtn = my_compute_power_rec(16, 4);
    cr_assert_eq(rtn, 65536);
}

Test (my_compute_square_root, compute_root, .init = redirect_all_std)
{
    int rtn = 0;

    rtn = my_compute_square_root(16);
    cr_assert_eq(rtn, 4);
}