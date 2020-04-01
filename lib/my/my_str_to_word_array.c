/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#include <stdlib.h>

static int is_alphanum(char const *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        return (1);
    else if (str[i] >= 'a' && str[i] <= 'z')
        return (1);
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    return (0);
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static int calc_row(char const *str)
{
    int i = 0;
    int row = 1;

    for (i = 0; !is_alphanum(str, i); i++);
    i += (!is_alphanum(str, i - 1)) ? 1 : 0;
    while (str[i] != '\0') {
        while (!is_alphanum(str, i) && str[i + 1] != '\0')
            i++;
        if (i != 0 && !is_alphanum(str, i - 1))
            row++;
        i++;
    }
    if (!is_alphanum(str, i - 1) && !is_alphanum(str, i - 2))
        row--;
    return (row);
}

static char **alloc_word_array(char const *str)
{
    char **array;
    int row;
    int i = 0;

    if (str == NULL)
        return (NULL);
    row = calc_row(str);
    array = malloc(sizeof(char *) * (row + 1));
    while (i != row) {
        array[i] = malloc(sizeof(char) * (my_strlen(str)) + 2);
        i++;
    }
    array[row] = NULL;
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    char **array = alloc_word_array(str);
    int row = 0;
    int col = 0;
    int i = 0;

    if (str == NULL)
        return (0);
    for (i = 0; !is_alphanum(str, i); i++);
    for (; str[i] != '\0'; i++) {
        if (is_alphanum(str, i)) {
            array[row][col] = str[i];
            col++;
        } else if (is_alphanum(str, i + 1) && !is_alphanum(str, i)) {
            array[row][col] = '\0';
            col = 0;
            row++;
        }
        array[row][col] = '\0';
    }
    return (array);
}