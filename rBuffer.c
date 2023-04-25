#include "main.h"

/**
  * reset_buffer - function that initializes and resets a buffer
  *
  * @buffer: buffer size
  *
  * Return: Nothing
  */
void reset_buffer(char *buffer)
{
	int i = 0;

	while (i < 1024)
		buffer[i++] = 0;

	buffer[i] = '\0';
}
