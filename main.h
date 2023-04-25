#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format - struct format
 *
 * @type: format type
 * @f: function
 */
typedef struct format
{
	char type;
	void (*f)(va_list, char *, int *);
} format_t;

int _putchar(char c);

int _printf(const char *format,  ...);

void print_c(va_list l, char *buffer, int *index);
void print_s(va_list l, char *buffer, int *index);
void print_perc(va_list l, char *buffer, int *index);
void print_d(va_list l, char *buffer, int *index);
void print_i(va_list l, char *buffer, int *index);
void print_u(va_list l, char *buffer, int *index);
void print_p(va_list l, char *buffer, int *index);
void print_lx(va_list l, char *buffer, int *index);
void print_h(va_list l, char *buffer, int *index);
void print_ch(va_list l, char *buffer, int *index);
void print_o(va_list l, char *buffer, int *index);
void print_b(va_list l, char *buffer, int *index);
void print_r(va_list l, char *buffer, int *index);
void print_R(va_list l, char *buffer, int *index);

void print_char(va_list l);
void print_string(va_list l);
void print_int(va_list l);
void print_float(va_list l);

int _strlen(char *s);
int num_len(int num);
int float_len(double f);
int num_len(int num);

void rev_string(char *s);
void _write_buffer(char *buffer, int *index);
void reset_buffer(char buffer[]);

char *_memcpy(char *dest, char *src, unsigned int n);
char *itos(char str[], long int num);
char *utos(char str[], int num);
char *tostring(char str[], int num);
void *rot13(char *s);

#endif
