/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <fcntl.h>
#include "printf.h"

int count_space(char *, char);
char **cut_str(char *, char);
char *chartostr(char c);
void destroy_array(char **);
char *get_next_line(int);
int get_size_array(char **);
char *get_word(char *, char);
char **giga_cut_str(char *, char *);
char *inttochar(int nb);
int is_in_str(char *, char);
int is_letter(char);
int my_getnbr(char *);
long long my_getnbr_long(char *);
char *my_itoa(int);
void my_memset(void *, int, size_t);
int my_put_nbr(int);
void my_putchar(char);
void my_puterror(char *);
int my_putstr(char *);
char *my_revstr(char *);
int my_str_isalpha(char *);
int my_str_islower(char *);
int my_str_isnum(char *);
int my_str_isprintable(char *);
int my_str_isupper(char *);
char *my_strcat(char *, char *);
char *my_strcatf(char *, char *);
char *my_strcatff(char *, char *);
char *my_strcat_f(char *, char *);
int my_strcmp(char *, char *);
char *my_strcpy(char *);
char *my_strdup(char *);
char *my_strfdup(char *);
char *my_strfndup(char *, int);
int my_strlen(char *);
char *my_strlowcase(char *);
int my_strncmp(char *, char *, int);
char *my_strndup(char *, int);
char *my_strupcase(char *);
int my_printf(char *, ...);
void print_array(char **);
char *read_fic(char *);
char **supra_cut_str(char *, char **);

#endif /* !MY_H_ */
