/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** print string
*/

void my_putchar(char);
void my_errchar(char);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int my_errstr(char const *str)
{
    int i = 0;

    while (str[i]) {
        my_errchar(str[i]);
        i++;
    }
    return 0;
}
