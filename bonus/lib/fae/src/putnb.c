/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Display a number.
*/

#include "fae.h"

static void infae_display_number(int nb, int stream)
{
    int length = fae_nblen(nb);
    int to_display = 0;

    for (int index = length; index > 0; index--) {
        to_display = (nb / fae_power(10, index - 1)) % 10;
        to_display *= (nb < 0) ? -1 : 1;
        fae_sputchar(to_display + '0', stream);
    }
}

void fae_putnb(int nb, int stream)
{
    if (nb == 0) {
        fae_putchar('0');
        return;
    }
    if (nb < 0){
        fae_putchar('-');
    }
    infae_display_number(nb, stream);
}

void fae_putfloat(float nb, int precision)
{
    if (nb == 0) {
        fae_putchar('0');
        return;
    }
    if (nb < 0){
        fae_putchar('-');
    }
    infae_display_number((int)(nb), 1);
    nb = (nb - ((int)(nb))) * precision;
    fae_putchar('.');
    infae_display_number((int)(nb), 1);
    for (int i = fae_nblen((int)(nb)); i < precision; i++)
        fae_putchar('0');
}

static char infae_rec_putbase(int nb, char const *base, int length)
{

    if (nb != 0)
        infae_rec_putbase(nb / length, base, length);
    else
        return 0;
    if (nb < 0)
        fae_putchar(base[- (nb % length)]);
    else
        fae_putchar(base[nb % length]);
}

void fae_putbase(int nb, char const *base)
{
    int base_len = fae_strlen(base);

    if (!base || base[0] == '\0')
        return;
    if (nb == 0) {
        fae_putchar(base[0]);
        return;
    }
    (nb < 0) ? fae_putchar('-') : 1;
    infae_rec_putbase(nb, base, base_len);
}
