#include "main.h"

/**
 * print_perc - percent
 *
 * @l: va_list
 * @buffer: write to buffer
 * @index: the index
 *
 * Return: Nothing
 */
void print_perc(__attribute__((unused)) va_list l, char *buffer, int *index)
{
	buffer[*index] = '%';
	*index += 1;
}
