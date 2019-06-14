/*
** EPITECH PROJECT, 2018
** lib
** File description:
** file to string
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *ftostr(char const *filename)
{
    int fd = -1;
    struct stat st;
    char *content;

    if (stat(filename, &st) == -1) {
        my_errstr(TBRD "Error:" TRST " could not open file\n");
        exit(84);
    }
    content = malloc(sizeof(char) * (st.st_size + 1));
    content[st.st_size] = '\0';
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        my_errstr(TBRD "Error:" TRST " could not open file\n");
        exit(84);
    }
    if (read(fd, content, st.st_size) == 0) {
        my_errstr(TBRD "Error:" TRST " invalid file\n");
    }
    return content;
}
