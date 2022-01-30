/*
** EPITECH PROJECT, 2019
** inc
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include "../../lib/include/my.h"
#include "../op.h"

#ifndef MACRO_
#define MACRO_

#define SUCCESS (0)
#define ERROR (84)
#define PROBLEM (1)

#define IMP_SIZE (size) ? ((*size) += DIR_SIZE) : (0)
#define IMP_LAB_SIZE (size) ? ((*size) += check_direct(cmd)) : (0)

#endif /* !MACRO_ */

#ifndef STRUCT_
#define STRUCT_

typedef struct container
{
    char **tab;
    char **args;
    int *size;
    int cur_i;
    int i;
    int fd;
    int direct;
}t_st;

#endif /* !STRUCT_ */

#ifndef INC_
#define INC_

/* binary_to_decimal.c */

char *decimal_binary(int nb);
int binary(char *str);

/* header.c */

char *recover_name(char *name);
int stock_prog_name(header_t *he, char **stock_all, char *line_name, int find);
int stock_prog_com(header_t *he, char **stock_all, char *comment, int find);
int init_struct_header_sec(char **stock_all, int find, header_t *he, int found);
header_t *init_struct_header(char **stock_all);

/* args.c */

int is_in_str(char *str, char c);
int check_args(char **action, char **tab, int *size);
int is_direct_byte(char *cmd, char *str);
void args_byte(char *act, char **args, int fd);
void other_assemb_cmd(t_st *src, char *sto);

/* struct.c */

char *remove_comment(char *str);
t_st *create_struct(char *line);
void destroy(t_st *src);

/* read_champ.c */

char **stock_all_file(char *filepath);
void find_prog_name_sec(char *line_name, char **stock_all, int y, int *x);
int find_prog_name(char **stock_all, char *line_name);
int is_direct_cmd(char *str);
int is_indirect_cmd(char *str);

/* fic.c */

int print_fic(header_t *he, char *name, t_st *src);
char **cut_line(char *str);

/* arg_type.c */

int is_register(char *str, int *size);
int is_direct(char *cmd, char *str, char **tab, int *size);
int check_direct(char *str);
int is_indirect(char *str, char **tab, int *size);
int is_rule(char *str, char **tab, int *size);

/* main.c */

int main(int ac, char **av);

/* code_int.c */

char *invert_all(char *str);
char *add_one_binary(char *str);
void set_nb_neg(int fd, int n, int size);
void set_nb(int fd, int n);
void set_nb_size(int fd, int n, int size);

/* cmd.c */

int check_assemb_cmd(char *str);
int check_assemb_tab(char *str);
int check_existing_cmd(char *str, char **all_cmd);
int check_first_cmd(char *str, int *size);
int check_existing_label(char *str, int i, char **tab);

/* encode.c */

int calc_len(int i, int *size, int count, t_st *src);
void encode_direct(t_st *src, char *str);
int calc_ind(int i, int *size, int count, t_st *src);
void encode_indirect(t_st *src, char *str);

/* name.c */

int check_name(char **t, int *test);
int check_comment(char *line);
int check_empty_label(char **action, int *size);
int is_name(char *str);

/* parse.c */

int check_line(char **tab, int *line_size, int i);
int verif_pattern(char **tab, int *size, int **tab_int);
void function_set_all(t_st *src, char *sto);
void choose_op(char **action, char *name, t_st *src);
int parse_champ(char *line, header_t *he, char *fic_name);

/* verif_header.c */

int verif_all_second(char **stock_all);
int verif_all(char **stock_all, int find);


#endif /* !INC_ */

#endif /* !COREWAR_H_ */