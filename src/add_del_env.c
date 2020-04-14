/*
** EPITECH PROJECT, 2019
** add_del_env
** File description:
** Add to setenv, remove from setenv
*/

#include "basic.h"

char **add_env(char **tab, char **env)
{
    int i = 0;
    char **new_env = NULL;

    for (; env[i]; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    new_env[i + 1] = NULL;
    for (int j = 0; j < i; j++)
        new_env[j] = env[j];
    if (tab[1] != NULL)
        new_env[i] = my_strcat(tab[1], "=");
    if (tab[2] != NULL)
        new_env[i] = my_strcat(new_env[i], tab[2]);
    return (new_env);
}

char **remove_env(char **env, int i)
{
    int k = 0;
    char **new_env = NULL;

    for (; env[k]; k++);
    new_env = malloc(sizeof(char *) * (k + 1));
    new_env[k] = NULL;
    k = 0;
    for (int x = 0; env[x]; x++)
        if (x != i) {
            new_env[k] = env[x];
            k++;
        }
    return (new_env);
}