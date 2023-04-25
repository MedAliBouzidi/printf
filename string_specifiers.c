#include "main.h"

/**
 * print_s - specifier s
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_s(va_list l, char *buffer, int *index)
{
	int i, j;
	char *s;

	s = va_arg(l, char*);

	if (s == NULL)
		s = "(null)";

    i = *index, j = 0;
	while ( *(s + j))
	{
		if (*index == 1024)
		{
			_write_buffer(buffer, index);
			reset_buffer(buffer);
			*index = 0;
		}
		buffer[*index] = *(s + j);
        *index += 1, i++, j++;
	}
}

/**
 * print_c - specifier c
 *
 * @l: va_list
 * @buffer: buffer
 * @index: index
 *
 * Return: Nothing
 */
void print_c(va_list l, char *buffer, int *index)
{
	char s;

	s = va_arg(l, int);

	if (*index == 1024)
	{
		_write_buffer(buffer, index);
		reset_buffer(buffer);
		*index = 0;
	}

	buffer[*index] = s;
	*index += 1;
}
