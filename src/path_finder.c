/*
** EPITECH PROJECT, 2019
** path_finder.c
** File description:
** Returns the possible paths from env
*/

#include <basic.h>

char **my_path_gen(void)
{
    char **tab = malloc(sizeof(char *) * 9);

    tab[8] = NULL;
    tab[0] = my_strdup("PATH=/home/Greg/.local/bin");
    tab[1] = my_strdup("/home/Greg/bin");
    tab[2] = my_strdup("/usr/local/bin");
    tab[3] = my_strdup("/usr/bin");
    tab[4] = my_strdup("/bin");
    tab[5] = my_strdup("/usr/local/sbin");
    tab[6] = my_strdup("/usr/sbin");
    tab[7] = my_strdup("/var/lib/snapd/snap/bin");
    return (tab);
}

int is_path(char *str)
{
    if (my_strlen(str) > 3 && str[0] == 'P' && str[1] == 'A' &&
        str[2] == 'T' && str[3] == 'H')
        return (1);
    return (0);
}

char **path_finder(char **env)
{
    char **tab = NULL;

    for (int i = 0; env[i]; i++)
        if (is_path(env[i])) {
            tab = my_str_to_double_point(env[i]);
            return (tab);
        }
    tab = my_path_gen();
    return (tab);
}