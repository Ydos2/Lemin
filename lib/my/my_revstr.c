/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int i = 0;
    char c;
    int x = 0;

    if (str == 0)
        return (0);
    while (str[i] != '\0')
        i++;
    i--;
    for (int x = 0; x < i; x++, i--) {
        c = str[x];
        str[x] = str[i];
        str[i] = c;
    }
    return (str);
}