/*
** EPITECH PROJECT, 2019
** error_not_found.c
** File description:
** Error display when not found
*/

#include "basic.h"

void error_not_found(char *cmd)
{
    my_putstr(cmd);
    write(1, ": Command not found.\n", 21);
}