/*
** EPITECH PROJECT, 2019
** banned_functions.c
** File description:
** Handle banned functions
*/

#include <basic.h>

int banned_function(tab_s *data)
{
    if (is_cd(data->tab)) {
        my_cd(data);
        return (1);
    }
    if (is_env(data->tab)) {
        my_env(data->env);
        return (1);
    }
    if (is_setenv(data->tab)) {
        my_setenv(data);
        return (1);
    }
    if (is_unsetenv(data->tab)) {
        my_unsetenv(data);
        return (1);
    }
    return (0);
}