#include "main.h"

/**
 * print_d - function that returns an int to signed decimal
 *
 * @l: arguments passed
 * @buffer: values stored
 * @index: tracks index position
 *
 * Return: Nothing
 */
void print_d(va_list l, char *buffer, int *index)
{
	int i, j, ln;
	char *num_str;

	i = va_arg(l, int);

	ln = num_len(i);
	if (i < 0)
		ln += 1;

	num_str = malloc(ln * sizeof(char));
	if (num_str == NULL)
		return;

    itos(num_str, i);

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
