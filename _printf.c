#include "main.h"

/**
  * _printf - function that prints based on format specifier
  * @format: takes in format specifier
  * Return: return pointer to index
  */
int _printf(const char *format, ...)
{
	char buffer[1024];
	int i, j = 0, a = 0, *index = &a;
	va_list l;
	format_t spec[] = {
		{'c',  print_c}, {'d',  print_d}, {'s',  print_s}, {'i',  print_d},
		{'u',  print_u}, {'%',  print_perc}, {'x',  print_h}, {'X',  print_ch},
		{'o',  print_o}, {'b',  print_b}, {'p',  print_p}, {'r',  print_r},
		{'R',  print_R}, {'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(l, format);
	while (*(format + i))
	{
		while (*(format + i) != '%' && *(format + i))
		{
			if (*index == 1024)
			{
				_write_buffer(buffer, index);
				reset_buffer(buffer);
				*index = 0;
			}
			buffer[*index] = format[i];
		}
		if (*(format + i) == '\0')
			break;
		if (*(format + i) == '%')
		{
			i++;
			while (spec[j].type)
			{
				if (*(format + i) == spec[j].type)
				{
					spec[j].f(l, buffer, index);
					break;
				}
				j++;
			}
		}
		i++;
	}
	va_end(l);
	buffer[*index] = '\0';
	_write_buffer(buffer, index);
	return (*index);
}
