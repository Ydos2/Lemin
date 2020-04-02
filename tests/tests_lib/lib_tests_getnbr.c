/*
** EPITECH PROJECT, 2020
** lib_tests_getnbr
** File description:
** lib_tests_getnbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_getnbr, rtn_19, .init = redirect_all_std)
{
    int rtn = 0;

    rtn = my_getnbr("19");
    cr_assert_eq(rtn, 19);
}