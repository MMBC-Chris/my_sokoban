/*
** EPITECH PROJECT, 2018
** Day05
** File description:
** test if prime
*/

int is_prime(int nb, int i)
{
    if (nb <= 2)
        return nb == 2;
    if (!(nb % i))
        return 0;
    if (i * i > nb)
        return 1;

    return is_prime(nb, i + 1);
}

int my_is_prime(int nb)
{
    return is_prime(nb, 2);
}
