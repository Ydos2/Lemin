/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_user_entry
*/

#include <stdlib.h>
#include <stdio.h>

char *get_user_entry(char *old_entry)
{
    size_t size = 0;

    if (old_entry)
        free (old_entry);
    old_entry = NULL;
    size = getline(&old_entry, &size, stdin);
    if (size == -1)
        return (NULL);
    old_entry[old_entry[size - 1] == '\n' ? size - 1 : size] = '\0';
    return (old_entry);
}