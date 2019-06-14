/*
** EPITECH PROJECT, 2018
** Day05
** File description:
** sqrt
*/

int sqr(int i, int square, int nb)
{
    if (square == nb)
        return i;
    else if (square > nb)
        return 0;
    else
        return sqr(i + 1, (i + 1) * (i + 1), nb);
}

int my_compute_square_root(int nb)
{
    if (nb < 0)
        return 0;
    else
        return sqr(0, 0, nb);
}
