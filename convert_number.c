#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED CONVERT | CONVERT_LOWECASE, params);
	if (params->hastag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}

/**
 * print_HEx - prints unsigned hex numbers in uppercase
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: byte printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifiest)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 0, CONVERT_UNSIGNED, PARAMS);
	if (params->hastag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, parent));
}

/**
 * Print_binary - prints unsigned binary number
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char str = convert(n, 2, CONVERT_UNSIGNED, parent);
	int c = 0;

	if (params->hastag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - print unsigned octal numbers
 * @ap; argument pointer
 * @params: parameters struct
 *
 * Return: byte printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 0, CONVERT_UNIGNED, params);

	if (params->hastag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
