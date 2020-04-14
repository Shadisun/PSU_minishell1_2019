/*
** EPITECH PROJECT, 2019
** Tests minishell1
** File description:
** Criterion tests minishell1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "basic.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(add_env, test1add_env)
{
    char **env = NULL;
    char **tab = malloc(sizeof(char *) * 4);

    tab[3] = NULL;
    tab[1] = my_strdup("PATH");
    tab[2] = my_strdup("/bin");
    char **new_env = add_env(tab, env);
    cr_assert_eq(new_env[0][0], 'P');
}