/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:16 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:17 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_wchr(va_list list, t_arg *arg)
{
	wchar_t		wc;

	wc = va_arg(list, wchar_t);
	if (ft_strchr2(arg->flags, '-'))
	{
		ft_putwchar(wc);
		print_padded_char(arg->field_width - 1, arg, ' ');
	}
	else
	{
		print_padded_char(arg->field_width - 1, arg, ' ');
		ft_putwchar(wc);
	}
	return (arg->print_count + 1);
}
