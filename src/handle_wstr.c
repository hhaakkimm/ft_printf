/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:28:18 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:28:19 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_wstr(va_list list, t_arg *arg)
{
	wchar_t	*arg_wstr;
	int		arg_len;
	int		min_print;

	arg_wstr = va_arg(list, wchar_t *);
	arg_len = ft_wstrlen(arg_wstr);
	min_print = ft_min(arg->precision_nb, arg_len);
	wstr_output(arg, arg_wstr, arg_len, min_print);
	return (arg->print_count);
}

void	wstr_output(t_arg *arg, wchar_t *arg_wstr, int arg_len, int min_print)
{
	if ((arg->precision && arg->field_width == 0) || arg->width_nb < min_print)
	{
		arg->print_count += min_print;
		ft_putnwstr(arg_wstr, arg->print_count);
	}
	else if (arg->field_width == 1 || arg->width_nb > min_print)
	{
		if (ft_strchr2(arg->flags, '-'))
		{
			ft_putnwstr(arg_wstr, min_print);
			print_padded_char(arg->field_width - min_print, arg, ' ');
		}
		else
		{
			print_padded_char(arg->field_width - min_print, arg, ' ');
			ft_putnwstr(arg_wstr, min_print);
		}
		arg->print_count += min_print;
	}
	else
	{
		ft_putwstr(arg_wstr);
		arg->print_count += arg_len;
	}
}
