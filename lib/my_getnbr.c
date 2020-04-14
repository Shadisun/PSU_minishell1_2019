/*
** EPITECH PROJECT, 2019
** task05
** File description:
** my get nbr
*/

int is_neg(char const *str, int *nb)
{
    int neg = 1;

    while (str[*nb] == 43 || str[*nb] == 45) {
        if (str[*nb] == 45)
            neg = neg * -1;
        (*nb)++;
    }
    return neg;
}

void count_num(char const *str, int *nb, long int *count)
{
    while (str[*nb] >= 48 && str[*nb] <= 57) {
        *count = *count * 10;
        (*nb)++;
    }
}

int my_getnbr(char const *str)
{
    long int count = 1;
    int nb = 0;
    long int somme = 0;
    int i = 0;
    int neg = 1;

    neg = is_neg(str, &nb);
    i = nb;
    count_num(str, &nb, &count);
    for ( ; i < nb; i++){
        count = count/10;
        somme = somme + (str[i]-48)*count;
    }
    if (somme * neg < -2147483648 || somme * neg > 2147483647)
        return (0);
    else
        return (somme * neg);
}
