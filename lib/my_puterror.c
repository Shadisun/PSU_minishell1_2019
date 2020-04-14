/*
** EPITECH PROJECT, 2018
** my_puterror
** File description:
** putstr
*/

#include "basic.h"

void my_puterror(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    write(2, str, i);
}