/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_user_entry
*/

#include <stdlib.h>
#include <stdio.h>

static void add_entry_to_tunnels(char *old_entry, char ***tunnels_stdin)
{
    char **new_tunnels = NULL;
    int length = 0;

    for (; (*tunnels_stdin)[length]; length++);
    new_tunnels = malloc(sizeof(char *) * (length + 2));
    for (int i = 0; i < length; i++)
        new_tunnels[i] = (*tunnels_stdin)[i];
    new_tunnels[length] = old_entry;
    new_tunnels[length + 1] = NULL;
    free(*tunnels_stdin);
    *tunnels_stdin = new_tunnels;
}

char *get_user_entry(char *old_entry, char ***tunnels_stdin)
{
    size_t size = 0;

    old_entry = NULL;
    size = getline(&old_entry, &size, stdin);
    if (size == -1)
        return (NULL);
    old_entry[old_entry[size - 1] == '\n' ? size - 1 : size] = '\0';
    add_entry_to_tunnels(old_entry, tunnels_stdin);
    return (old_entry);
}