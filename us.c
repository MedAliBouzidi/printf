#include "main.h"

/**
 * print_u - specifier for u
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_u(va_list l, char *buffer, int *index)
{
	unsigned int i;
	int j, ln;
	char *num_str;

	i = va_arg(l, int);
	ln = num_len(i);
	num_str = malloc(ln * sizeof(char));

	if (num_str == NULL)
		return;

	utos(num_str, i);

	i = *index, j = 0;
	while (j < ln)
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = num_str[j];
		*index += 1, i++, j++;
	}

	free(num_str);
}

/**
 * print_h - specifier for h
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_h(va_list l, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hex_values;
	char *hex;

	n = va_arg(l, int);
	hex_values = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));

	if (hex == NULL)
		return;

	i = 0;
	while (n != 0)
	{
		hex[i++] = hex_values[n % 16];
		n /= 16;
	}

	i--;
	while (i >= 0)
	{
		buffer[*index] = hex[i];
		*index += 1, i--;
	}

	free(hex);
}

/**
 * print_ch - specifier for ch
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_ch(va_list l, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *hex_values;
	char *hex;

	n = va_arg(l, int);
	hex_values = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));

	if (hex == NULL)
		return;

	i = 0;
	while (n != 0)
	{
		hex[i++] = hex_values[n % 16];
		n /= 16;
	}

	i--;
	while (i >= 0)
	{
		buffer[*index] = hex[i];
		*index += 1, i--;
	}

	free(hex);
}

/**
 * print_o - specifier for o
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_o(va_list l, char *buffer, int *index)
{
	unsigned int n;
	int i;
	char *oct_values;
	char *oct;

	n = va_arg(l, int);
	oct_values = "0123456789ABCDEF";
	oct = malloc(12 * sizeof(char));

	if (oct == NULL)
		return;

	i = 0;
	while (n != 0)
	{
		oct[i++] = oct_values[n % 8];
		n /= 8;
	}

	i--;
	while (i >= 0)
	{
		buffer[*index] = oct[i];
		*index += 1, i--;
	}

	free(oct);
}
