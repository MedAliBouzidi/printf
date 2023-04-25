#include "main.h"

/**
 * print_R - function that converts a string into rot13
 *
 * @l: argument passed
 * @buffer: values stored
 * @index: tracks index position
 *
 * Return: Nothing
 */
void print_R(va_list l, char *buffer, int *index)
{
	int i, j;
	char *s;
	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	s = va_arg(l, char *);

	i = 0;
	while (*(s + i))
	{
		j = 0;
		while (*(s1 + j))
		{
			if (*(s + i) == *(s1 + j))
				buffer[*index] = *(s2 + j);
			else if (*(s + i) == *(s2 + j))
				buffer[*index] = *(s1 + j);
			j++;
		}
		i++, *index += 1;
	}
}
