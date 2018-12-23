/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:30 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:34 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			str_type(char c, va_list list, t_arg *arg)
{
	if (c == 's')
		return (handle_str(list, arg));
	else if (c == 'S')
		return (handle_wstr(list, arg));
	else if (c == 'c')
		return (handle_chr(list, arg));
	else if (c == 'C')
		return (handle_wchr(list, arg));
	else
		return (handle_percent(list, arg));
}

int			handlers(char **format, va_list list, t_arg *arg)
{
	char			c;

	parse_conversion(format, arg);
	c = arg->conversion;
	if (c == 's' || c == 'S' || c == 'c' || c == 'C' || c == '%')
		return str_type(c, list, arg);
	else if (c == 'p')
		return handle_ptr(list, arg);
	else if (c == 'd' || c == 'D' || c == 'i')
		return handle_int(list, arg);
	else if (c == 'o' || c == 'O')
		return handle_octal(list, arg);
	else if (c == 'u' || c == 'U')
		return handle_unsigned(list, arg);
	else if (c == 'x' || c == 'X')
		return handle_hex(list, arg);
	else if (c == 'f' || c == 'F')
		return (handle_float(list, arg));
	c = **format;
	if (ft_strchr2("+-0 #.hl", c))
		return (-1);
	else
		return (0);
}
