/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** minishell 1 main
*/

#include "basic.h"

static void error_handling(int argc)
{
    if (argc != 1)
        exit(84);
}

static char *exit_test(char *line)
{
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        if (isatty(STDIN_FILENO))
            write(1, "exit\n", 5);
        exit(0);
    }
    for (int i = 0; line[i]; i++)
        if (line[i] == '\n' && (my_strlen(line) != 1))
            line[i] = '\0';
    exit_line(line);
    return (line);
}

static tab_s *init_data(char **env)
{
    tab_s *data = malloc(sizeof(tab_s));

    data->tab = NULL;
    data->env = env;
    data->path = NULL;
    return (data);
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    char **my_env = my_dup_env(env);
    tab_s *data = init_data(my_env);

    (void)argv;
    error_handling(argc);
    signal(SIGINT, signal_handler);
    data->env = delete_oldpwd(data->env);
    while (1) {
        if (isatty(STDIN_FILENO))
            write(1, "$> ", 3);
        line = exit_test(line);
        if (line[0] == '\n')
            continue;
        data->tab = my_str_to_word_array(line);
        run_prog(data);
        free(line);
        line = NULL;
    }//FREE ????
}//Boucle principale dans le main X