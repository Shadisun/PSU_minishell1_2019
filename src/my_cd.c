/*
** EPITECH PROJECT, 2019
** my_cd.c
** File description:
** my change directory minishell
*/

#include <basic.h>

void my_cd_minus(tab_s *data)
{
    char *path = NULL;

    for (int k = 0; data->env[k]; k++)
        if (data->env[k][0] == 'O' && data->env[k][1] == 'L' && data->env[k][2]
            == 'D' && data->env[k][3] == 'P' && data->env[k][4] == 'W'
            && data->env[k][5] == 'D') {
            path = my_strdup(data->env[k] + 7);
            chdir(path);
            set_oldpwd(data);
            set_pwd(data);
            return;
        }
    write(1, ": No such file or directory.\n", 29);
}

int is_cd(char **tab)
{
    if (my_strlen(tab[0]) == 2 && tab[0][0] == 'c' && tab[0][1] == 'd')
        return (1);
    return (0);
}

void error_cd(char *path)
{
    struct stat data;

    my_putstr(path);
    if (stat(path, &data) != -1)
        if (!S_ISDIR(data.st_mode)) {
            write(1, ": Not a directory.\n", 19);
            return;
        }
    write(1, ": No such file or directory.\n", 29);
}

char *get_user_path(char **env)
{
    char *user = NULL;

    for (int i = 0; env[i]; i++)
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M')
            user = my_strdup(env[i] + 5);
    return (user);
}

void my_cd(tab_s *data)
{
    char *path = NULL;

    if (data->tab[1] == NULL)
        path = get_user_path(data->env);
    else if (my_strlen(data->tab[1]) == 1 && data->tab[1][0] == '-' &&
        data->tab[2] == NULL) {
        my_cd_minus(data);
        return;
    }
    else
        path = data->tab[1];
    if (chdir(path) != -1) {
        set_oldpwd(data);
        set_pwd(data);
        return;
    }
    error_cd(path);
}