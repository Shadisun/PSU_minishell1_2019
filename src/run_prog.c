/*
** EPITECH PROJECT, 2019
** run_prog.c
** File description:
** Receives a path then runs the program
*/

#include <wait.h>
#include <string.h>
#include "basic.h"

static void signal_print(int status)
{
    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case 11:
                write(2, "Segmentation fault", 18);
                break;
            case 8:
                write(2, "Floating exception", 18);
                break;
        }
        if (WTERMSIG(status) != 11 && WTERMSIG(status) != 8)
            my_puterror(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(1, "\n", 1);
    }
}

static void delete_path(tab_s *data)
{
    free(data->path);
    data->path = NULL;
}

void run_prog(tab_s *data)
{
    int status = 0;
    pid_t i;

    special_path_cases(data);
    if ((data->path == NULL))
        return;
    free(data->tab[0]);
    data->tab[0] = data->path;
    i = fork();
    if (i == 0) {
        if (execve(data->tab[0], data->tab, data->env) == -1)
            exit(84);
    } else if (i > 0)
        waitpid(i, &status, 0);
    signal_print(status);
    delete_path(data);
}