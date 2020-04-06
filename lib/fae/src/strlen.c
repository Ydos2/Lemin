/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** return length of a string
*/

int fae_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return 0;
    for (; str[len]; len++);
    return len;
}
