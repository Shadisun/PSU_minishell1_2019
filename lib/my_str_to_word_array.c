/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** [fill]
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "basic.h"

static char *malloc_str(char *str, int size)
{
    str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < (size + 1); i++)
        str[i] = '\0';
    return (str);
}

static char **fill_tab(char **tab, char *str)
{
    int i = 0;
    int j = 0;
    int rk = 0;

    while (str[i]) {
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); i++);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            tab[rk][j] = str[i];
            j++;
            i++;
        }
        rk++;
        j = 0;
    }
    return (tab);
}

static char **malloc_tab(char **tab, char *str, int lines)
{
    int i = 0;
    int j = 0;
    int rk = 0;

    tab = malloc(sizeof(char *) * (lines + 1));
    tab[lines] = NULL;
    for (; str[i] == ' ' || str[i] == '\t'; i++);
    while (str[i]) {
        for (; str[i] && (str[i] == ' ' || str[i] == '\t'); j = 0, i++);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            j++;
            i++;
        }
        tab[rk] = malloc_str(tab[rk], j);
        rk++;
        j = 0;
    }
    return (tab);
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;
    int nb = 0;
    int i = 0;
    int j = my_strlen(str);

    while (str[j - 1] == ' ' || str[j - 1] == '\t') {
        str[j - 1] = '\0';
        j--;
    }
    for (; str[i] == ' ' || str[i] == '\t'; i++);
    while (str[i]) {
        if (str[i] != ' ' && str[i] != '\t')
            i++;
        if (str[i] == ' ' || str[i] == '\t')
            nb++;
        for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++);
    }
    tab = malloc_tab(tab, str, nb + 1);
    tab = fill_tab(tab, str);
    return (tab);
}