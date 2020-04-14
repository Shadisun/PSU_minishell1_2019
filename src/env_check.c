/*
** EPITECH PROJECT, 2019
** env_check.c
** File description:
** Checks if the variable exists in the environment
*/

#include "basic.h"

int env_check(char *str, char **env, int k)
{
    for (int j = 0; j < my_strlen(str); j++)
        if (str[j] != env[k][j])
            return (-1);
    return (k);
}