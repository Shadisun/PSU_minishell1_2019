/*
** EPITECH PROJECT, 2019
** my_setenv.c
** File description:
** My own setenv
*/

#include "basic.h"

char **replace_line_env(char **tab, char **env, int line)
{
    free(env[line]);
    env[line] = my_strcat(tab[1], "=");
    if (tab[2] != NULL)
        env[line] = my_strcat(env[line], tab[2]);
    return (env);
}

static int modify_existent_env(tab_s *data)
{
    int i = 0;

    for (int k = 0; data->env[k]; k++)
        if ((i = env_check(data->tab[1], data->env, k)) != -1) {
            data->env = replace_line_env(data->tab, data->env, i);
            return (1);
        }
    return (0);
}

int is_setenv(char **tab)
{
    if (my_strlen(tab[0]) == 6)
        if (tab[0][0] == 's' && tab[0][1] == 'e' && tab[0][2] == 't' &&
            tab[0][3] == 'e' && tab[0][4] == 'n' && tab[0][5] == 'v')
            return (1);
    return (0);
}

void my_setenv(tab_s *data)
{
    if (data->tab[1] != NULL && data->tab[2] != NULL && data->tab[3] != NULL) {
        write(1, "setenv: Too many arguments.\n", 28);
        return;
    }
    if (data->tab[1] == NULL) {
        my_env(data->env);
        return;
    }
    if ((data->tab[1][0] < 65 || data->tab[1][0] > 90) &&
        (data->tab[1][0] < 97 || data->tab[1][0] > 122)) {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return;
    }
    if (modify_existent_env(data))
        return;
    data->env = add_env(data->tab, data->env);
}