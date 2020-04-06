/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Display a number.
*/

#include "../dep_linked_list.h"

static int list_get_int_length(int nb)
{
    int length = 0;

    while (nb >= 1 || nb <= -1) {
        length++;
        nb = (int) (nb / 10);
    }
    return length;
}

static int list_pw10(int pw)
{
    int nb = 1;
    while (pw > 0) {
        nb *= 10;
        pw--;
    }
    return nb;
}

static void list_display_number(int nb)
{
    int length;
    int to_display;
    int calcul_division;

    length = list_get_int_length(nb);
    for (int index = length; index > 0; index--) {
        to_display = nb;
        if (index > 1) {
            calcul_division = list_pw10(index - 1);
            to_display = (int) (to_display / calcul_division);
        }
        to_display %= 10;
        if (nb < 0) {
            to_display = - to_display;
        }
        list_putchar(to_display + '0');
    }
}

int list_put_nbr(int nb)
{
    if (nb == 0)
        list_putchar('0');
    if (nb < 0){
        list_putchar('-');
    }
    list_display_number(nb);
    return 0;
}
