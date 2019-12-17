/*
** EPITECH PROJECT, 2019
** getnextline
** File description:
** getnextline
*/

#include "get_next_line.h"
#include "my.h"

char *get_next_line(int fd)
{
    static char *buff;
    char *result;
    int i = 0;
    val_t *val = NULL;

    val = malloc(sizeof(val_t));
    val->turn = 1;
    val->carac = 0;
    while (val->turn != 0) {
        val->turn = 0;
        buff = read_next_n_bytes(fd, READ_SIZE);
        if (buff) {
            i = read_and_display_read_line_n(buff, val);
            result = append(result, buff, i, val);
        }
    }
    free(val);
    return (result);
    //return (NULL);
}

char *read_next_n_bytes(int fd, int n)
{
    char *buff = malloc(sizeof(char) * n + 1);
    int op = 0;

    op = read(fd, buff, n);
    if (op <= 0)
        return (NULL);
    buff[n+1] = '\0';
    return (buff);
}

int read_and_display_read_line_n(char *buff, val_t *val)
{
    int i = 0;
    int turn_val = 0;

    for (i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n') {
            turn_val++;
            break;
        }
    if (turn_val == 0)
        val->turn++;
    return (i);
}

char *append(char *result, char *buff, int i, val_t *val)
{
    int j = 0;

    val->carac += i;
    result = malloc(sizeof(char) * val->carac + 1);
    for (; j != val->carac-i; j++)
        result[j] = val->buff_inter[j];
    for (int k = 0; j != val->carac; j++, k++)
        result[j] = buff[k];
    val->buff_inter = malloc(sizeof(char) * val->carac);
    for (int z = 0; z != val->carac; z++)
        val->buff_inter[z] = result[z];
    result[val->carac+1] = '\0';
    return (result);
}