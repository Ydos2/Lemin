/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** return the number len.
*/

int fae_nblen(int nb)
{
    int length = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        length++;
        nb /= 10;
    }
    return length;
}
