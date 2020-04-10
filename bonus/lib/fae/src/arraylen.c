/*
** EPITECH PROJECT, 2019
** libfae
** File description:
** Compare two string
*/

int fae_arraylen(void **array)
{
    int len = 0;

    if (!array)
        return 0;
    for (; array[len]; len++);
    return len;
}
