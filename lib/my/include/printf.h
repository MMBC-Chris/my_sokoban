/*
** EPITECH PROJECT, 2018
** My Printf
** File description:
** func pointers
*/

#ifndef _PRINTF_H_
#define _PRINTF_H_

typedef struct
{
    char const *identifier;
    int (*print)(va_list);
} format_t;

int print_int(va_list);
int print_uint(va_list);
int print_char(va_list);
int print_str(va_list);
int print_hex_lwc(va_list);
int print_hex_upc(va_list);
int print_ubin(va_list);
int print_octal(va_list);
int print_ptr(va_list);
int print_invisible_str(va_list);

#define FORMATS_NUM 11

format_t const PRINTF_FORMATS[FORMATS_NUM] =
{
    {"d", &print_int},
    {"i", &print_int},
    {"u", &print_uint},
    {"c", &print_char},
    {"s", &print_str},
    {"x", &print_hex_lwc},
    {"X", &print_hex_upc},
    {"o", &print_octal},
    {"b", &print_ubin},
    {"p", &print_ptr},
    {"S", &print_invisible_str}
};

#endif
