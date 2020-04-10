/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_compute_square_root(int nb)
{
    long long i = 0;

    if (nb <= 0)
        return (0);
    while (i * i < nb && i * i < 2147483647)
        i++;
    if (i * i == nb)
        return (i);
    else
        return (0);
}