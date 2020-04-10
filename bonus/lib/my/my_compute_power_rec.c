/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_compute_power_rec(int nb, int p)
{
    long long anti_crash = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    anti_crash *= my_compute_power_rec(nb, p - 1);
    if (anti_crash > 2147483647 || anti_crash < -2147483648)
        return (0);
    return (anti_crash);
}