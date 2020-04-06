/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** show non printable characters in string
*/

#include "fae.h"

static void infae_add_zero(int nb)
{
    if (nb < 16)
        my_putchar('0');
}

int fae_show_np(char const *str)
{
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] < 32) {
            my_putchar('\\');
            infae_add_zero(str[c]);
            my_putnbr_base(str[c], "0123456789abcdef");
        } else
            my_putchar(str[c]);
    }
}
