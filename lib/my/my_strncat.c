/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

static int get_dest_len(char *dest)
{
    int i = 0;

    if (dest == 0)
        return (0);
    while (dest[i] != '\0')
        i++;
    return (i);
}

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int dest_len = get_dest_len(dest);

    if (src == 0)
        return (dest);
    if (dest == 0)
        return (0);
    while (src[i] != '\0' && i < n) {
        dest[dest_len + i] = src[i];
        i++;
    }
    return (dest);
}