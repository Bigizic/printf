#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;
/* check the next character after '.' to see if it's a digit or '*', return -1 as the precision */
	curr_i++;
	if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
	}
	else if (isdigit(format[curr_i]))
	{
		while (isdigit(format[curr_i]))
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
	}
		else
		{
			return (-1);
		}
		*i = curr_i - 1;
		/* if the conversion specifier is 's' or 'd' return -1 as the precision */
		if (format[*i + 1] == 's' || format[*i + 1] == 'd')
				{
				return (-1);
				}
		return (precision);

}

