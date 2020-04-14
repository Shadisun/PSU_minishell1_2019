/*
** EPITECH PROJECT, 2019
** exit_line.c
** File description:
** Exit handling
*/

#include <basic.h>

int is_no_numeric(char * str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}

void exit_line(char *line)
{
    char **tab = my_str_to_word_array(line);
    if (my_strlen(tab[0]) == 4 && tab[0][0] == 'e' && tab[0][1] == 'x' &&
        tab[0][2] == 'i' && tab[0][3] == 't') {
        if (tab[1] == NULL) {
            write(1, "exit\n", 5);
            exit(0);
        }
        if (is_no_numeric(tab[1]) == 0) {
            write(1, "exit\n", 5);
            exit(my_getnbr(tab[1]));
        }
        write(1, "exit: Expression Syntax.\n", 25);
        line[0] = '\n';
    }
}