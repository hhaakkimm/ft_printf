/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:56 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:27:57 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		handle_int(va_list list, t_arg *arg)
{
	int			i;
	intmax_t	nb;
	int			arg_len;

	if (arg->precision || ft_chr2(arg->flags, '-'))
	{
		i = -1;
		while (++i < 6)
			if (arg->flags[i] == '0')
				arg->flags[i] = 'x';
	}
	if ((nb = get_int_type_by_length(list, arg)) < 0)
	{
		nb = -nb;
		arg->neg_arg = 1;
	}
	arg_len = ft_nbrlen(nb);
	return (int_output_helper(arg, nb, arg_len));
}

int		int_output_helper(t_arg *arg, intmax_t nb, int arg_len)
{
	if (!ft_chr2(arg->flags, '-') && !ft_chr2(arg->flags, '0'))
	{
		if (arg->precision == 1 && arg->pre_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			else if (nb == 0)
				return (0);
			else if (nb != 0)
			{
				ft_putnbr_intmax_t(nb);
				arg->print_count += arg_len;
			}
			return (arg->print_count);
		}
		int_output1(nb, arg, arg_len);
	}
	else if (ft_chr2(arg->flags, '-'))
		int_output2(nb, arg, arg_len);
	else if (ft_chr2(arg->flags, '0'))
		int_output3(nb, arg, arg_len);
	arg->print_count += arg_len;
	return (arg->print_count);
}

void	int_output1(intmax_t nb, t_arg *arg, int arg_len)
{
	intmax_t	pad_space_nb;
	intmax_t	pad_zero_nb;

	pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->pre_nb - arg_len, 0);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb >= pad_space_nb)
		{
			print_int_sign(arg);
			print_padded_char(pad_zero_nb, arg, '0');
		}
		if (pad_zero_nb < pad_space_nb)
		{
			if (ft_chr2(arg->flags, '+') || ft_chr2(arg->flags, ' ') ||
			arg->neg_arg)
				pad_space_nb -= 1;
			print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
			print_int_sign(arg);
			print_padded_char(pad_zero_nb, arg, '0');
		}
	}
	else if (pad_space_nb <= 0 && pad_zero_nb <= 0)
		print_int_sign(arg);
	ft_putnbr_intmax_t(nb);
}

void	int_output2(intmax_t nb, t_arg *arg, int arg_len)
{
	intmax_t	pad_space_nb;
	intmax_t	pad_zero_nb;

	if (ft_chr2(arg->flags, '+') || ft_chr2(arg->flags, ' ') || arg->neg_arg)
		pad_space_nb = ft_max(arg->width_nb - arg_len - 1, 0);
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->pre_nb - arg_len, 0);
	print_int_sign(arg);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putnbr_intmax_t(nb);
	print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
}

void	int_output3(intmax_t nb, t_arg *arg, int arg_len)
{
	intmax_t	pad_zero_nb;

	if (arg->neg_arg)
	{
		pad_zero_nb = ft_max(arg->width_nb - arg_len - 1, 0);
		print_int_sign(arg);
	}
	else
	{
		if (ft_chr2(arg->flags, '+') || ft_chr2(arg->flags, ' '))
		{
			print_int_sign(arg);
			pad_zero_nb = ft_max(arg->width_nb - arg_len - 1, 0);
		}
		else
			pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
	}
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putnbr_intmax_t(nb);
}
