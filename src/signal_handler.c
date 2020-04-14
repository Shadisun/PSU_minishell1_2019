/*
** EPITECH PROJECT, 2019
** signal_handler.c
** File description:
** my_signal_handler
*/

#include "basic.h"

void signal_handler(int signalValue)
{
    write(1, "\n$> ", 4);
}