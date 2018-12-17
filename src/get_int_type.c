#include "../includes/ft_printf.h"

intmax_t	get_int_type_by_length(va_list list, t_arg *arg)
{
	intmax_t	nb;

	nb = va_arg(list, intmax_t);
	if (arg->length == h && arg->conversion != 'D')
		nb = (short int)nb;
	else if (arg->length == l || arg->conversion == 'D')
		nb = (long int)nb;
	else if (arg->length == hh)
		nb = (signed char)nb;
	else if (arg->length == ll)
		nb = (long long int)nb;
	else if (arg->length == j)
		nb = (intmax_t)nb;
	else if (arg->length == z)
		nb = (size_t)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t	get_unsigned_type_by_length(va_list list, t_arg *arg)
{
	uintmax_t	nb;

	nb = va_arg(list, intmax_t);
	if (arg->length == h && arg->conversion != 'U' && arg->conversion != 'O')
		nb = (unsigned short int)nb;
	else if (arg->length == l || arg->conversion == 'U' ||
			arg->conversion == 'O')
		nb = (unsigned long int)nb;
	else if (arg->length == hh)
		nb = (unsigned char)nb;
	else if (arg->length == ll)
		nb = (unsigned long long int)nb;
	else if (arg->length == j)
		nb = (uintmax_t)nb;
	else if (arg->length == z)
		nb = (size_t)nb;
	else
		nb = (unsigned int)nb;
	return (nb);
}
