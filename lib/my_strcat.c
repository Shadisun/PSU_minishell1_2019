/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** concat 2 strings
*/

#include "basic.h"

char *my_strcat(char *str_d, char *str_c)
{
    int k = 0;
    int i = my_strlen(str_d) + my_strlen(str_c);
    char *cat = malloc(sizeof(char) * (i + 1));

    for (int j = 0; j < i + 1; j++)
        cat[j] = '\0';
    for (; str_d[k]; k++)
        cat[k] = str_d[k];
    for (int j = 0; str_c[j]; j++, k++)
        cat[k] = str_c[j];
    return (cat);
}