/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** swap two integers
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
