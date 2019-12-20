/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <fcntl.h>
#include <string.h>

#ifndef READ_SIZE
#define READ_SIZE (3)
#endif /* READ_SIZE */

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

char *get_next_line(int fd);
char *read_next_n_bytes(int fd, int n, int count_run, char *buff);
int read_and_display_read_line_n(char *buff, val_t *val);
char *append(char *result, char *buff, int i, val_t *val);
int set_end(val_t *val);

#endif /* !GET_NEXT_LINE_H_ */