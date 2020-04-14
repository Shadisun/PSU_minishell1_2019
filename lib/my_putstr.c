/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** putstr
*/

#include "basic.h"

void my_putstr(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(1, str, i);
}
