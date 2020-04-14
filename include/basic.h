/*
** EPITECH PROJECT, 2019
** basic.h
** File description:
** [...]
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <signal.h>

typedef struct {
    char **tab;
    char **env;
    char *path;
} tab_s;

//LIB

int my_getnbr(char const *str);
void my_puterror(char const *str);
void my_putstr(char const *str);
char *my_strcat(char *str_d, char *str_c);
char *my_strdup(char *str);
int my_strlen(char *str);
char **my_str_to_double_point(char *str);
char **my_str_to_word_array(char *str);

//MAIN

char **add_env(char **tab, char **env);
int banned_function(tab_s *data);
char **delete_oldpwd(char **env);
int env_check(char *str, char **env, int k);
void exit_line(char *line);
char *get_path(tab_s *data);
int is_cd(char **tab);
int is_env(char **tab);
int is_setenv(char **tab);
int is_unsetenv(char **tab);
void my_cd(tab_s *data);
char **my_dup_env(char **env);
void my_env(char **env);
void my_setenv(tab_s *data);
void my_unsetenv(tab_s *data);
char **path_finder(char **env);
char **remove_env(char **env, int i);
char **replace_line_env(char **tab, char **env, int line);
void run_prog(tab_s *data);
void set_oldpwd(tab_s *data);
void set_pwd(tab_s *data);
void signal_handler(int signalValue);

//ERRORS

void error_not_found(char *cmd);
void special_path_cases(tab_s *data);

#endif
