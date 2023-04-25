#include "main.h"

/**
 * print_p - function that print a pointer address
 *
 * @l: argument list
 * @buffer: values stored
 * @index: tracks the index position
 *
 * Return: Nothing
 */
void print_p(va_list l, char *buffer, int *index)
{
	print_lx(l, buffer, index);
}

/**
 * print_lx - function that prints a long address
 *
 * @l: argument list
 * @buffer: values stored
 * @index: tracks the index position
 *
 * Return: Nothing
 */
void print_lx(va_list l, char *buffer, int *index)
{
	unsigned long int n;
	int i = 0;
	char *hex_values, *hex, *b;
	void *a;

	a = va_arg(l, void *);
	b = "(nil)";

	if (a == NULL)
		while (i < 5)
		{
			buffer[*index] = b[i];
			i++, *index += 1;
		}

	n = (unsigned long int) a;

	hex_values = "0123456789abcdef";
	hex = malloc(14 * sizeof(char));

	i = 0;
	while (n != 0)
	{
		hex[i++] = hex_values[n % 16];
		n /= 16;
	}

	i += 2;
	hex[13] = '0';
	hex[12] = 'x';

	i--;
	while (i >= 0)
	{
		buffer[*index] = hex[i];
		*index += 1, i--;
	}
}
