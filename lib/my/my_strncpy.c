/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == 0 || src == 0 || n == 0)
        return (dest);
    while (src[i] != '\0' && i != n) {
        dest[i] = src[i];
        i++;
    }
    if (n > i)
        dest[i] = '\0';
    return (dest);
}