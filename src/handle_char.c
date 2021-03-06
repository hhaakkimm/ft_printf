/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:26:43 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:26:45 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_chr(va_list list, t_arg *arg)
{
	char	c;

	if (arg->length == l)
	{
		arg->print_count = handle_wchr(list, arg);
		return (arg->print_count);
	}
	c = va_arg(list, int);
	if (ft_chr2(arg->flags, '-'))
	{
		ft_putchar(c);
		print_padded_char(arg->width_nb - 1, arg, ' ');
	}
	else
	{
		if (ft_chr2(arg->flags, '0'))
			print_padded_char(arg->width_nb - 1, arg, '0');
		else
			print_padded_char(arg->width_nb - 1, arg, ' ');
		ft_putchar(c);
	}
	return (arg->print_count + 1);
}
