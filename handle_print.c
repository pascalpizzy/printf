#include "main.h"

/**
 * handle_print - Print an argument that is type based.
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Pointer to the index of the current format specifier in the format string.
 * @buffer: Buffer array to handle print.
 * @flags: Calculate all the active flags.
 * @width: Get the width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Return -1 on error or Number of characters printed.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;

	/* List of format specifiers and their corresponding print functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			/* Call the appropriate print function for the format specifier */
			return fmt_types[i].fn(list, buffer, flags, width, precision, size);
		}
	}

	/* If the format specifier is not recognized */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return -1;

		/* Handle the case when '%' is followed by unknown characters */
		unknow_len += write(1, "%%", 1);

		/* If there was a space before '%', write a space */
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			/* If there is a width specifier, move the index to the beginning of the width */
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);

			/* If the current character is ' ', move back again to cover the space case */
			if (fmt[*ind] == ' ')
				--(*ind);

			return 1;
		}

		unknow_len += write(1, &fmt[*ind], 1);
		return unknow_len;
	}

	return printed_chars;
}

