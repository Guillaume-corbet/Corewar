/*
** EPITECH PROJECT, 2019
** args type
** File description:
** corewar
*/

#include "../include/corewar.h"

int is_register(char *str, int *size)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i] == 'r' && my_str_isnum(str + i + 1) == SUCCESS &&
    my_getnbr(str + i + 1) > 0 && my_getnbr(str + i + 1) <= REG_NUMBER) {
        if (size)
            (*size) += 1;
        return (SUCCESS);
    }
    return (PROBLEM);
}

int is_direct(char *cmd, char *str, char **tab, int *size)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i] == DIRECT_CHAR) {
        if (my_str_isnum(str + i + 1) == SUCCESS &&
        my_strlen(str + i + 1) > 0) {
            IMP_LAB_SIZE;
            return (SUCCESS);
        }
        if (str[i + 1] == LABEL_CHAR && (check_assemb_cmd(str + i + 2) == 0
        || check_existing_cmd(str + i + 2, tab) == 0) &&
        my_strlen(str + i + 1) > 0) {
            IMP_LAB_SIZE;
            return (SUCCESS);
        }
    }
    return (PROBLEM);
}

int check_direct(char *str)
{
    if (my_strlen(str) < 3)
        return (4);
    if ((my_strncmp(str, "zjmp", 4) == 0 && (!str[4] || str[4] != LABEL_CHAR))
    || (my_strncmp(str, "ldi", 3) == 0 && (!str[3] || str[3] != LABEL_CHAR))
    || (my_strncmp(str, "sti", 3) == 0 && (!str[3] || str[3] != LABEL_CHAR))
    || (my_strncmp(str, "fork", 4) == 0 && (!str[4] || str[4] != LABEL_CHAR))
    || (my_strncmp(str, "lfork", 5) == 0 && (!str[5] || str[5] != LABEL_CHAR))
    || (my_strncmp(str, "lldi", 4) == 0 && (!str[4] || str[4] != LABEL_CHAR)))
        return (2);
    return (4);
}

int is_indirect(char *str, char **tab, int *size)
{
    int i = 0;

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (my_str_isnum(str + i) == 0 || (str[i] == LABEL_CHAR &&
    (check_assemb_cmd(str + i + 1) == 0 ||
    check_existing_cmd(str + i + 1, tab) == 0))) {
        if (size)
            (*size) += IND_SIZE;
        return (SUCCESS);
    }
    return (PROBLEM);
}

int is_rule(char *str, char **tab, int *size)
{
    int i = 0;
    char **rule_args = cut_line(str);

    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (check_assemb_cmd(str + i) == 0) {
        if (check_args(rule_args, tab, size) == 0) {
            destroy_array(rule_args);
            return (SUCCESS);
        }
    }
    destroy_array(rule_args);
    return (PROBLEM);
}