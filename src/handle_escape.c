/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:51 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:52 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_percent(va_list list, t_arg *arg)
{
	(void)list;
	if (ft_strchr2(arg->flags, '-'))
	{
		ft_putchar('%');
		print_padded_char(arg->width_nb - 1, arg, ' ');
	}
	else
	{
		if (ft_strchr2(arg->flags, '0'))
			print_padded_char(arg->width_nb - 1, arg, '0');
		else
		{
			print_padded_char(arg->width_nb - 1, arg, ' ');
		}
		ft_putchar('%');
	}
	return (arg->print_count + 1);
}
