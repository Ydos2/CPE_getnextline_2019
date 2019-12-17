/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_
#define READ_SIZE (1000)
#include <fcntl.h>

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

char *get_next_line(int fd);
char *read_next_n_bytes(int fd, int n);
int read_and_display_read_line_n(char *buff, val_t *val);
char *append(char *result, char *buff, int i, val_t *val);

#endif /* !GET_NEXT_LINE_H_ */