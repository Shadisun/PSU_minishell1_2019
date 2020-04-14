/*
** EPITECH PROJECT, 2019
** my_unsetenv.c
** File description:
** removes a variable from local env
*/

#include "basic.h"

int is_unsetenv(char **tab)
{
    if (my_strlen(tab[0]) == 8)
        if (tab[0][0] == 'u' && tab[0][1] == 'n' && tab[0][2] == 's' &&
            tab[0][3] == 'e' && tab[0][4] == 't' && tab[0][5] == 'e' &&
            tab[0][6] == 'n' && tab[0][7] == 'v')
            return (1);
    return (0);
}

//static void sub_unsetenv(tab_s *data, )

void my_unsetenv(tab_s *data)
{
    int i = 0;

    if (data->tab[1] == NULL) {
        write(1, "unsetenv: Too few arguments.\n", 29);
        return;
    }
    for (int x = 1; data->tab[x]; x++)
        for (int k = 0; data->env[k]; k++)
            if ((i = env_check(data->tab[x], data->env, k)) != -1)
                data->env = remove_env(data->env, i);
}