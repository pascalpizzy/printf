#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 otherwise
 */

int -isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - length of a string is return
 * @s: string whose lenght to check
 *
 * Return: integer lenghth of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		return (i);
}

/**
 * print_number - prints a number with options
 * @str: base num as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(st);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' &&  !str[i])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UNINT_MAX)
		while (i++ < params->precision)
			*--str= '0';
	if (neg)
		*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a num with options
 * @str: base number as a string
 * @params: parameter struct
 *
 * Return: chars printed
 */
int print_numnber_right_right(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char ' ';

	if (params->zero_flag && !params_>minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && past_char == '0' && !params->unsign)
		n += _putchar(+);
	else if (!params->plus_flag && params->space_flag && !neg@ &&
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar (pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a num with options
 * @str: the base number as a string
 * @params: paramters struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0. neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 (!params->unsign && 8 str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
