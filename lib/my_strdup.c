/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** duplicates a string
*/

#include "basic.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *dup = NULL;

    if (str == NULL)
        return (NULL);
    for (; str[i]; i++);
    dup = malloc(sizeof(char) * (i + 1));
    dup[i] = '\0';
    for (int j = 0; j < i; j++)
        dup[j] = str[j];
    return (dup);
}