/*
** EPITECH PROJECT, 2019
** my_env.c
** File description:
** Displays the environment
*/

#include "basic.h"

int is_env(char **tab)
{
    if (my_strlen(tab[0]) == 3)
        if (tab[0][0] == 'e' && tab[0][1] == 'n' && tab[0][2] == 'v')
            return (1);
    return (0);
}

void my_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_putstr(env[i]);
        write(1, "\n", 1);
    }
}