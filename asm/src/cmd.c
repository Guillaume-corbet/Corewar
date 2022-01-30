/*
** EPITECH PROJECT, 2019
** cmd
** File description:
** corewar
*/

#include "../include/corewar.h"

int check_assemb_cmd(char *str)
{
    int len;

    for (int i = 0; op_tab[i].mnemonique; i++) {
        len = my_strlen(op_tab[i].mnemonique);
        if (my_strncmp(op_tab[i].mnemonique, str, len) == SUCCESS &&
        (!str[len] || (str[len] && (str[len] == ' ' || str[len] == '\t'))))
            return (SUCCESS);
    }
    return (PROBLEM);
}

int check_assemb_tab(char *str)
{
    int len;

    for (int i = 0; op_tab[i].mnemonique; i++) {
        len = my_strlen(op_tab[i].mnemonique);
        if (my_strncmp(op_tab[i].mnemonique, str, len) == SUCCESS &&
        (!str[len] || str[len] == ' ' || str[len] == '\t'))
            return (i);
    }
    return (-1);
}

int check_existing_cmd(char *str, char **all_cmd)
{
    int i = 0;

    while (all_cmd[i]) {
        if (my_strncmp(all_cmd[i], str, my_strlen(str)) == 0)
            return (SUCCESS);
        i++;
    }
    return (PROBLEM);
}

int check_first_cmd(char *str, int *size)
{
    if (my_strncmp(str, "live", 4) != 0 && my_strncmp(str, "zjmp", 4) != 0
    && my_strncmp(str, "fork", 4) != 0 && my_strncmp(str, "lfork", 5) != 0)
        (*size)++;
    if (str[my_strlen(str) - 1] != LABEL_CHAR) {
        (*size)++;
        return (check_assemb_cmd(str));
    }
    for (int i = 0; str[i]; i++) {
        if (is_in_str(LABEL_CHARS, str[i]) != SUCCESS && str[i] != LABEL_CHAR)
            return (PROBLEM);
    }
    return (SUCCESS);
}

int check_existing_label(char *str, int i, char **tab)
{
    int k = 0;

    while (str[k] && str[k] != ' ' && str[k] != '\t')
        k++;
    if (k > 0 && str[k - 1] != LABEL_CHAR)
        return (PROBLEM);
    for (int j = 0; tab[j] && j < i; j++) {
        if (my_strncmp(tab[j], str, k - 1) == 0 && my_strlen(tab[j]) > k - 1)
            return (SUCCESS);
    }
    return (PROBLEM);
}