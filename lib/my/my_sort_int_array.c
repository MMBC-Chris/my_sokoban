/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** sort array of int
*/

int find_swap(int *array, int i, int size)
{
    int min = array[i];
    int j = i + 1;
    int index = i;

    while (j < size) {
        if (array[j] < min) {
            min = array[j];
            index = j;
        }
        j++;
    }
    return index;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int swap_index = 0;
    int tmp = 0;

    while (i < size -1) {
        swap_index = find_swap(array, i, size);
        if (swap_index != i) {
            tmp = array[i];
            array[i] = array[swap_index];
            array[swap_index] = tmp;
        }
        i++;
    }
}
