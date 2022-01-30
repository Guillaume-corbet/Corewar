/*
** EPITECH PROJECT, 2019
** name
** File description:
** corewar
*/

#include "../include/corewar.h"

int check_name(char **t, int *test)
{
    int ret = PROBLEM;

    if (t[1] && my_strncmp(t[0], NAME_CMD_STRING,
    my_strlen(NAME_CMD_STRING)) == 0 && my_strlen(t[1]) > 2) {
        (*test) = 1;
        if (t[1] && t[1][0] == '"' && t[1][my_strlen(t[1]) - 1] == '"')
            ret = SUCCESS;
    }
    if (t[1] && (*test) == 1 && my_strncmp(t[0], COMMENT_CMD_STRING,
    my_strlen(COMMENT_CMD_STRING)) == 0) {
        if (t[1] && t[1][0] == '"' && t[1][my_strlen(t[1]) - 1] == '"')
            ret = SUCCESS;
    }
    return (ret);
}

int check_comment(char *line)
{
    int i = 0;

    while (line[i] && (line[i] == ' ' || line[i] == '\t'))
        i++;
    if (line[i] == COMMENT_CHAR)
        return (SUCCESS);
    return (PROBLEM);
}

int check_empty_label(char **action, int *size)
{
    int test = 0;

    if (!action)
        return (PROBLEM);
    if (action[0][my_strlen(action[0]) - 1] == LABEL_CHAR && !action[1]) {
        test = 1;
    }
    for (int i = 0; action[0][i] && test == 1; i++) {
        if (is_in_str(LABEL_CHARS, action[0][i]) != SUCCESS &&
        action[0][i] != LABEL_CHAR)
            return (PROBLEM);
    }
    if (test == 1)
        return (SUCCESS);
    return (PROBLEM);
}

int is_name(char *str)
{
    if (my_strncmp(str, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0 ||
    my_strncmp(str, COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING)) == 0) {
        return (SUCCESS);
    }
    return (PROBLEM);
}