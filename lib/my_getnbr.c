/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** Returns a number given as a string.
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int s = 1;
    int xnb;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            s = s * (-1);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        xnb = nb;
        nb = nb * 10 + (str[i] - 48);
        if (xnb > nb) {
            if (nb == -2147483648)
                return (nb);
            return (0);
        }
        i++;
    }
    return (s * nb);
}
