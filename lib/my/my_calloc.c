/*
** EPITECH PROJECT, 2018
** My Lib
** File description:
** calloc implementation
*/

#include <stddef.h>
#include <stdlib.h>

void *my_memset(void *block, int value, size_t n)
{
    unsigned char *ptr = block;

    for (; n; n--)
        *ptr++ = (unsigned char)(value);
    return block;
}

void *my_calloc(size_t elem_size, size_t elems)
{
    size_t alloc_size = elem_size * elems;
    void *block = malloc(alloc_size);

    return my_memset(block, 0, alloc_size);
}