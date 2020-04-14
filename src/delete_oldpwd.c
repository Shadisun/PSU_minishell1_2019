/*
** EPITECH PROJECT, 2019
** delete_oldpwd.c
** File description:
** Removes the oldpwd from the environment
*/

#include "basic.h"

char **delete_oldpwd(char **env)
{
    for (int i = 0; env[i]; i++)
        if (env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
            env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')
            env = remove_env(env, i);
    return (env);
}