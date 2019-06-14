/*
** EPITECH PROJECT, 2018
** Day05
** File description:
** find smallest prime number greater than or equal to n
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return nb;
    else
        return my_find_prime_sup(nb + 1);
}
