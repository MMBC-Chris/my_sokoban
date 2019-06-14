/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** atoi duplicate
*/

int valid_char(char c)
{
    int cond1 = c >= '0' && c <= '9';
    int cond2 = c == '+' || c == '-';

    return cond1 || cond2;
}

int is_number(char const *str)
{
    int i = 0;
    int f = 0;

    if (!valid_char(*str))
        return 0;
    while (str[i]) {
        if (!valid_char(str[i]) && !f)
            return 0;
        if (str[i] >= '0' && str[i] <= '9')
            f = 1;
        i++;
    }
    return f;
}

int overflow(long num, int neg)
{
    int nb = (int)(num);

    if (num > 2147483647 || num < -2147483648)
        return 0;
    else
        return neg ? -num : num;
}

void parse_sign(char c, int *neg, long *number, int *f)
{
    if (c == '-')
        *neg = !(*neg);
    else if (c != '+') {
        *number = *number * 10 + c - '0';
        *f = 1;
    }
}

int my_getnbr(char const *str)
{
    long number = 0;
    int i = 0;
    int f = 0;
    int neg = 0;

    if (!is_number(str))
        return 0;
    while (str[i]) {
        if (!valid_char(str[i]) && f)
            return overflow(number, neg);
        else
            parse_sign(str[i], &neg, &number, &f);
        i++;
    }
    if (neg)
        number = 0 - number;
    return number;
}
