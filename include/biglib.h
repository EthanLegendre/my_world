/*
** EPITECH PROJECT, 2025
** biglib
** File description:
** biglib
*/

#ifndef BIG_LIB
    #define BIG_LIB
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #define VALUE 1000007

int get_len_tab_int(int **tab);
int get_len_tab_str(char **tab);
int **mem_alloc_2d_array_int(int nbr_line, int nbr_column);
char **mem_alloc_2d_array_str(int nbr_line, int nbr_column);
void my_sort_int_array(int *tab, int size);
char *convert_exadecimal(unsigned int n);
int len_size(unsigned int n);
int convert_octal(int nb);
int convert_str_to_int(char *str);
char *create_path(char *name, char *d_name);
char *get_content_file(char *file_path);
int get_file_size(char *file_path);
void my_put_float(double nb, int decimal_precision);
int get_rounded(int nb);
int my_floatlen(int nb);
int get_int_len(int nb);
int my_get_number(char const *str);
int my_isneg(int n);
void my_put_number(int nb);
void my_swap(int *a, int *b);
void my_put_long(long nb);
int check_char_in_str(char *str, char c);
int my_put_str(char *str);
void my_putchar(char c);
char *my_revstr(char *str);
char *my_str_cat(char *dest, char const *src);
char *my_str_in_str(char *str, char *to_find);
char counting(char *str, char *to_find);
int my_str_is_alpha(char const *str);
int my_str_is_lower(char const *str);
int my_str_is_num(char const *str);
int my_str_is_upper(char const *str);
int my_str_len(char *str);
char *my_str_low_case(char *str);
char *my_str_ncat(char *dest, char const *src, int nb);
char *my_str_up_case(char *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char *src);
int my_strncmp(const char *s1, const char *s2, int n);
int my_char_is_alpha(char c);
char **my_str_to_word_array_by_chars(char *str, char *chars);
char **my_str_to_word_array(char *str);
char *get_content_proc(char *file);
char *convert_int_to_str(int nb);
int convert_str_to_int(char *str);
int *get_time_by_sec(long n);
void free_word_array(char **arr);
float convert_kb_to_mb(float kb);

#endif /* !BIG_LIB */
