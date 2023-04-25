#include "main.h"

/**
 * print_r - reverse a string passed in
 *
 * @l: argument passed in
 * @buffer: values stored
 * @index: returns pointer to index
 *
 * Return: Nothing
 */
void print_r(va_list l, char *buffer, int *index)
{
	int i, strlen;
	char *s;

	s = va_arg(l, char *);
	strlen = _strlen(s) - 1;

	i = strlen;
	while (i >= 0)
	{
		buffer[*index] = s[i];
		i--, *index += 1;
	}
}
