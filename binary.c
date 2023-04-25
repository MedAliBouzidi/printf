#include "main.h"

/**
 * print_b - function to convert to unsigned integer to binary
 *
 * @l: taking in arguments
 * @buffer: values stored
 * @index: tracks the index position
 *
 * Return: Nothing
 */
void print_b(va_list l, char *buffer, int *index) {
    unsigned int n;
    int i;
    char *binary_values;
    char *binary;

    n = va_arg(l, int);
    binary_values = "01";
    binary = malloc(33 * sizeof(char));

    if (binary == NULL)
        return;

    if (n == 0) {
        buffer[*index] = '0';
        *index += 1;
    } else {
        while (n != 0) {
            binary[i] = binary_values[n % 2];
            n /= 2;
            i++;
        }
        i--;
        while (i >= 0) {
            buffer[*index] = binary[i];
            *index += 1;
            i--;
        }
    }

    free(binary);
}
