/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == 0 || s2 == 0)
        return (0);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return ((s1[i] > s2[i]) ? 1 : -1);
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s1[i] != '\0' && s2[i] == '\0')
        return (1);
    return (0);
}