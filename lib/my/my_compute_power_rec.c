/*
** EPITECH PROJECT, 2018
** Day05
** File description:
** Recursive power computation
*/

int my_compute_power_rec(int nb, int p)
{
    long result = 0;

    if (p == 1)
        return nb;
    result = nb * my_compute_power_rec(nb, p - 1);
    if (result > 0x7FFFFFFF)
        return 0;
    return result;
}
