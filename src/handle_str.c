/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:07 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:08 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_str(va_list list, t_arg *arg)
{
	int		arg_len;

	if (arg->length == l)
	{
		arg_len = handle_wstr(list, arg);
		return (arg_len);
	}
	str_output(list, arg);
	return (arg->print_count);
}

void	str_output(va_list list, t_arg *arg)
{
	int		min_print;
	char	*arg_str;
	int		arg_len;

	if ((arg_str = va_arg(list, char *)) == NULL)
		arg_str = "(null)";
	arg_len = ft_strlen(arg_str);
	min_print = ft_min(arg->pre_nb, arg_len);
	(arg->precision == 0) ? min_print = arg_len : 1;
	arg->print_count = min_print;
	str_output_helper(arg, arg_str, min_print, arg_len);
}

void	str_output_helper(t_arg *arg, char *arg_str, int min_print, int arg_len)
{
	if ((arg->precision && arg->field_width == 0) || arg->width_nb < min_print)
		ft_putnstr(arg_str, arg->print_count);
	else if (arg->field_width == 1 || arg->width_nb > min_print)
	{
		if (ft_chr2(arg->flags, '-'))
		{
			ft_putnstr(arg_str, min_print);
			print_padded_char(arg->width_nb - min_print, arg, ' ');
		}
		else
		{
			print_padded_char(arg->width_nb - min_print, arg, ' ');
			ft_putnstr(arg_str, min_print);
		}
	}
	else
	{
		ft_putstr(arg_str);
		arg->print_count += arg_len;
	}
}
