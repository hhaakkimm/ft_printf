/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:28:12 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:28:13 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_unsigned(va_list list, t_arg *arg)
{
	uintmax_t	nb;
	char		*unsigned_str;
	int			arg_len;

	nb = get_unsigned_type_by_length(list, arg);
	unsigned_str = ft_itoa_base_uint(nb, 10, arg->conversion);
	arg_len = ft_strlen(unsigned_str);
	arg->print_count += arg_len;
	if (!ft_strchr2(arg->flags, '-') && !ft_strchr2(arg->flags, '0'))
		unsigned_output1(unsigned_str, arg, arg_len);
	else if (ft_strchr2(arg->flags, '-'))
		unsigned_output2(unsigned_str, arg, arg_len);
	else if (ft_strchr2(arg->flags, '0'))
		unsigned_output3(unsigned_str, arg, arg_len);
	free(unsigned_str);
	return (arg->print_count);
}

void	unsigned_output1(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
			print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(unsigned_str);
}

void	unsigned_output2(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb - pad_space_nb, arg, '0');
	ft_putstr(unsigned_str);
	print_padded_char(pad_space_nb, arg, ' ');
}

void	unsigned_output3(char *unsigned_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(unsigned_str);
}
