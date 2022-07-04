/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** pas besoin je pense que ta compris
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stdio.h>

typedef struct flags {
    char flags;
    void (*ptr) (va_list args);
} struct_flags;

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_put_nbr(int nb);
int my_printf(char *str, ...);
void my_put_float(float nb, int n);
int dec_to_binaire(int nbr);
int my_dec_to_hexa(int nbr);
int my_dec_to_octal(int nbr);
int my_dec_to_small_hexa(int nbr);
int my_compute_power_rec(int nb, int p);
int my_compute_power_it(int nb, int p);
void my_put_float2(float nb);
void pchar(va_list args);
void pstr(va_list args);
void pfloat(va_list args);
void pbin(va_list args);
void pnbr(va_list args);
void phexa(va_list args);
void poct(va_list args);
void pshexa(va_list args);
void percent(va_list args);
int my_getnbr(char *str);
char **my_str_to_array(char *str, char delim);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int fs_open_file(char const *filepath);
int my_getnbr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncpy (char *dest, char const *src, unsigned int n);
int my_index_of(char *str, char c);
char *my_strcpy_m(char const *str, unsigned int n);
char *my_cleanstr(char *str);
bool my_strncmp(char const *s1, char const *s2, size_t n);
size_t array_size(char **array);
void free_array(char **array);
#endif/* MY_H_*/
