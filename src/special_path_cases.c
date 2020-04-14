/*
** EPITECH PROJECT, 2019
** special_path_cases
** File description:
** Error and banned functions handling
*/

#include "basic.h"

void special_path_cases(tab_s *data)
{
    if (banned_function(data))
        return;
    data->path = get_path(data);
    if (data->path != NULL)
        if (my_strlen(data->path) > 2 && data->path[0] == ':' && data->path[1]
            == ':' && data->path[2] == ':')
            return;
    if (data->path == NULL) {
        error_not_found(data->tab[0]);
        return;
    }
}