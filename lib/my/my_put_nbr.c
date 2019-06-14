/*
** EPITECH PROJECT, 2018
** Day03
** File description:
** print number
*/

void my_putchar(char c);

int get_size(long nb)
{
    unsigned long size = 1;

    while ((nb / size) != 0)
        size *= 10;
    return size/10;
}

int test_negative(long nb)
{
    if (nb < 0)
        my_putchar('-');
    return (nb < 0) ? 1 : 0;
}

int my_put_nbr(long nb)
{
    long i = 1;
    char digit = '0';

    if (!nb) {
        my_putchar('0');
        return (0);
    }
    if (test_negative(nb))
        nb = -nb;
    i = get_size(nb);
    while (i > 0) {
        digit = (nb / i) % 10;
        if (digit < 0)
            digit = -digit;
        digit += '0';
        my_putchar(digit);
        i /= 10;
    }
    return (0);
}
