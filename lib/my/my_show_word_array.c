/*
** EPITECH PROJECT, 2018
** Day08
** File description:
** show array
*/

void my_putchar(char);
int my_putstr(char const *);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
