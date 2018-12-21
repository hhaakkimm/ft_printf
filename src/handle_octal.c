/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:26:59 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:00 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	oct_output1(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	if (ft_strchr2(arg->flags, '#'))
		pad_space_nb = ft_max(arg->width_nb - arg_len - 1, 0);
	pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	if (ft_strchr2(arg->flags, '#') && (pad_zero_nb >= pad_space_nb))
		print_hex_flag_hash(arg);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
		{
			if (ft_strchr2(arg->flags, '#'))
			{
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
				print_hex_flag_hash(arg);
			}
			else
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		}
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(oct_str);
}

void	oct_output2(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (ft_strchr2(arg->flags, '#'))
	{
		pad_space_nb = ft_max(arg->width_nb - arg_len - 1, 0);
		print_hex_flag_hash(arg);
		pad_zero_nb = ft_max(arg->precision_nb - arg_len - 1, 0);
	}
	else
	{
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
		pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	}
	if (pad_zero_nb >= pad_space_nb)
	{
		print_padded_char(pad_zero_nb, arg, '0');
		ft_putstr(oct_str);
	}
	else
	{
		print_padded_char(pad_zero_nb, arg, '0');
		ft_putstr(oct_str);
		print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
	}
}

void	oct_output3(char *oct_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	if (ft_strchr2(arg->flags, '#'))
	{
		pad_zero_nb = ft_max(arg->width_nb - arg_len - 1, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(oct_str);
}

int		handle_octal(va_list list, t_arg *arg)
{
	int			i;
	uintmax_t	nb;
	char		*oct_str;
	int			arg_len;

	nb = get_unsigned_type_by_length(list, arg);
	oct_str = ft_itoa_base_uint(nb, 8, arg->conversion);
	arg_len = ft_strlen(oct_str);
	if (!ft_strchr2(arg->flags, '-') && !ft_strchr2(arg->flags, '0'))
	{
		if (arg->precision == 1 && arg->precision_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			if (ft_strchr2(arg->flags, '#'))
				print_hex_flag_hash(arg);
			free(oct_str);
			return (arg->print_count);
		}
		if (nb == 0 && ft_strchr2(arg->flags, '#'))  
		{
			i = -1;
			while (++i < 6)
				if (arg->flags[i] == '#')
					arg->flags[i] = 'x';
		}
		oct_output1(oct_str, arg, arg_len);
	}
	else if (ft_strchr2(arg->flags, '-') || ft_strchr2(arg->flags, '0'))
		oct_output_helper(oct_str, arg, arg_len);
	free(oct_str);
	return (arg->print_count + arg_len);
}

void	oct_output_helper(char *oct_str, t_arg *arg, int arg_len)
{
	if (ft_strchr2(arg->flags, '-'))
		oct_output2(oct_str, arg, arg_len);
	else if (ft_strchr2(arg->flags, '0'))
		oct_output3(oct_str, arg, arg_len);
}
