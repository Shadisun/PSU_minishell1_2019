/*
** EPITECH PROJECT, 2019
** set_pwd.c
** File description:
** Set new and old pwd
*/

#include "basic.h"

int is_oldpwd(tab_s *data)
{
    for (int i = 0; data->env[i]; i++)
        if (data->env[i][0] == 'O' && data->env[i][1] == 'L' && data->env[i][2]
            == 'D' && data->env[i][3] == 'P' && data->env[i][4] == 'W' &&
            data->env[i][5] == 'D')
            return (i);
    return (-1);
}

void set_pwd(tab_s *data)
{
    char **tab = malloc(sizeof(char *) * 4);
    int i = 0;

    tab[3] = NULL;
    tab[0] = "setenv";
    tab[1] = "PWD";
    tab[2] = getcwd(NULL, 0);
    for (; data->env[i]; i++)
        if (data->env[i][0] == 'P' && data->env[i][1] == 'W' && data->env[i][2]
            == 'D')
            break;
    data->env = replace_line_env(tab, data->env, i);
    free(tab);
}

void set_oldpwd(tab_s *data)
{
    char **tab = malloc(sizeof(char *) * 4);
    int k = is_oldpwd(data);

    tab[3] = NULL;
    tab[0] = "setenv";
    tab[1] = "OLDPWD";

    for (int i = 0; data->env[i]; i++)
        if (data->env[i][0] == 'P' && data->env[i][1] == 'W' && data->env[i][2]
            == 'D')
            tab[2] = my_strdup(data->env[i] + 4);
    if (k == -1)
        data->env = add_env(tab, data->env);
    else
        data->env = replace_line_env(tab, data->env, k);
    free(tab);
}