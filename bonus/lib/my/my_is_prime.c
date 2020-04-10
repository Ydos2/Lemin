/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_is_prime(int nb)
{
    int divide;

    if (nb < 0 || nb == 0 || nb == 1)
        return (0);
    divide = nb / 2;
    while (divide != 1) {
        if ((nb / divide) * divide == nb)
            return (0);
        divide--;
    }
    return (1);
}