/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:26:52 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:26:53 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		hex_output1(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (ft_chr2(arg->flags, '#'))
		pad_space_nb = ft_max(arg->width_nb - arg_len - 2, 0);
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->pre_nb - arg_len, 0);
	if (ft_chr2(arg->flags, '#') && (pad_zero_nb >= pad_space_nb))
		print_hex_flag_hash(arg);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
		{
			if (ft_chr2(arg->flags, '#'))
			{
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
				print_hex_flag_hash(arg);
			}
			else
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		}
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(hex_str);
}

void		hex_output2(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (ft_chr2(arg->flags, '#'))
	{
		pad_space_nb = ft_max(arg->width_nb - arg_len - 2, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->width_nb - arg_len - 2, 0);
	print_padded_char(pad_zero_nb - pad_space_nb, arg, '0');
	ft_putstr(hex_str);
	print_padded_char(pad_space_nb, arg, ' ');
}

void		hex_output3(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	if (ft_chr2(arg->flags, '-'))
		hex_output2(hex_str, arg, arg_len);
	else if (ft_chr2(arg->flags, '0'))
	{
		if (ft_chr2(arg->flags, '#'))
		{
			pad_zero_nb = ft_max(arg->width_nb - arg_len - 2, 0);
			print_hex_flag_hash(arg);
		}
		else
			pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
		print_padded_char(pad_zero_nb, arg, '0');
		ft_putstr(hex_str);
	}
}

void		change_flags(t_arg *arg, char c1, char c2)
{
	int			i;

	i = -1;
	while (++i < 6)
		if (arg->flags[i] == c1)
			arg->flags[i] = c2;
}

int			handle_hex(va_list list, t_arg *arg)
{
	uintmax_t	nb;
	char		*hex_str;
	int			arg_len;

	if (arg->precision || ft_chr2(arg->flags, '-'))
		change_flags(arg, '0', 'x');
	if ((nb = get_unsigned_type_by_length(list, arg)) == 0)
		change_flags(arg, '#', 'x');
	hex_str = ft_itoa_base_uint(nb, 16, arg->conversion);
	arg_len = ft_strlen(hex_str);
	if (!ft_chr2(arg->flags, '-') && !ft_chr2(arg->flags, '0'))
	{
		if (arg->precision == 1 && arg->pre_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			free(hex_str);
			return (arg->print_count);
		}
		hex_output1(hex_str, arg, arg_len);
	}
	else if (ft_chr2(arg->flags, '-') || ft_chr2(arg->flags, '0'))
		hex_output3(hex_str, arg, arg_len);
	free(hex_str);
	return (arg->print_count + arg_len);
}
