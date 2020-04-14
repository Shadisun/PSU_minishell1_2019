/*
** EPITECH PROJECT, 2019
** get_path.c
** File description:
** Returns the programs path, NULL if doesn't exist
*/

#include <basic.h>

static char *check_folder(char *path)
{
    struct stat data;

    if (stat(path, &data) != -1)
        if (!S_ISREG(data.st_mode)) {
            my_putstr(path);
            write(2, ": Permission denied.\n", 21);
            return (":::");
        }
    return (path);
}

static int increase_cpt(char **tab, int i)
{
    for (int k = 5; tab[0][k]; k++) {
        tab[0][i] = tab[0][k];
        i++;
    }
    tab[0][i] = '\0';
    return (i);
}

static char *basic_test(tab_s *data)
{
    char *path = NULL;

    if (data->tab[0][0] == '.') {
        path = my_strdup(check_folder(data->tab[0]));
        if (access(path, F_OK) == 0 || (path != NULL && path[0] == ':'))
            return (path);
    }
    return (NULL);
}

static char *init_test(tab_s *data)
{
    char *path = NULL;

    if (access(data->tab[0], F_OK) == 0)
        path = my_strdup(check_folder(data->tab[0]));
    return (path);
}

char *get_path(tab_s *data)
{
    char **tab_env = path_finder(data->env);
    int i = 0;
    char *path = init_test(data);

    if (path != NULL)
        return (path);
    path = basic_test(data);
    if (path != NULL)
        return (path);
    i = increase_cpt(tab_env, i);
    for (i = 0; tab_env[i]; i++) {
        path = my_strcat(tab_env[i], "/");
        path = my_strcat(path, data->tab[0]);
        if (access(path, F_OK) == 0) {
            path = my_strdup(check_folder(path));
            return (path);
        }
    }
    return (NULL);
}