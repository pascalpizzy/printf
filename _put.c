#include "main.h"

/**
 * _puts - prints strings with a newline
 * @str: the string to print
 *
 * Return: void
 */
init _puts(char *str);
{
        char *a = str;

        while (*str)
                _putchar(*str++);
        return (str - a);
}
/**
 * _putchar - writes the char c to stdout
 * @c: The char to print
 *
 * Return: 1 on success.
 * on error, -1 is return on error and set appropriately.
 */
int _putchar(init c)
{
        static int i;
        static char but[output_BUF_SIZE];

        if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
        {
                write(1, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}
