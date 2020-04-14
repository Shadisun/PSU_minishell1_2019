/*
** EPITECH PROJECT, 2019
** my_dup_env
** File description:
** Duplicates environment
*/

#include "basic.h"

char **my_dup_env(char **env)
{
    char **new_env = NULL;
    int i = 0;

    for (; env[i]; i++);
    new_env = malloc(sizeof(char *) * (i + 1));
    new_env[i] = NULL;
    for (int j = 0; j < i; j++)
        new_env[j] = my_strdup(env[j]);
    return (new_env);
}