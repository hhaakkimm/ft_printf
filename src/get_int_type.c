/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:43 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:44 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else
		nb = (unsigned int)nb;
	return (nb);
}
