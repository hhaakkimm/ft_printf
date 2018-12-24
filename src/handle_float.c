/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 19:06:11 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/22 19:06:12 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	prepare_float(int *sign, long double *n, t_arg *f)
{
	long double	pi;
	int			i;

	i = 0;
	pi = 0.5;
	*sign = 0;
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	f->precision = (f->precision > -1) ? f->precision : 6;
	while (f->precision >= 0 && i++ < f->precision)
		pi /= 10;
	*n += pi;
}

static char	*ft_ftoa(long double n, t_arg *f)
{
	int		len;
	char	*dst;
	char	*dec;
	int		sign;
	int		pos;

	prepare_float(&sign, &n, f);
	dec = ft_llitoa_base((long long int)n, DECIMAL);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->precision > 0) ? f->precision : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->precision > 0)
		dst[pos++] = '.';
	while (pos < len + sign + ((f->precision > 0) ? (f->precision + 1) : 0))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	ft_strdel(&dec);
	return (dst);
}

char		*convert_float_nbr(void *p, t_flags *f)
{
	char	*str;

	str = NULL;
	str = ft_ftoa(*(long double*)p, f);
	return (str);
}

size_t		print_arg_float(va_list *args, t_flags *f)
{
	long double	n;

	if (f->type == TYPE_L)
		n = (double)va_arg(*args, double);
	else if (f->type == TYPE_LL)
		n = (long double)va_arg(*args, long double);
	else
		n = (double)va_arg(*args, double);
	return (fmt_putnbr(convert_float_nbr((void*)&n, f), f));
}


int		handle_float(va_list list, t_arg *arg)
{
	int			i;
	long double	nb;
	long double p;
	int			arg_len;
	int			len;

	if ((nb = get_float_len(list, arg)) < 0)
	{
		nb = -nb;
		arg->neg_arg_int = 1;
	}
	arg->precision = (arg->precision > -1) ? arg->precision : 6;
	i = arg->precision - 1;
	p = 0.5;
	while (i--)
		p /= 10;
	nb += p;
	len = ft_nbrlen(nb);
	if (arg->precision || ft_strchr2(arg->flags, '-'))
	{
		i = -1;
		while (++i < 6)
			if (arg->flags[i] == '0')
				arg->flags[i] = 'x';
	}
	if ((nb = get_float_len(list, arg)) < 0)
	{
		nb = -nb;
		arg->neg_arg_int = 1;
	}
	arg_len = ft_nbrlen(nb);
	return (int_output_helper(arg, nb, arg_len));
}

int		int_output_helper(t_arg *arg, intmax_t nb, int arg_len)
{
	if (!ft_strchr2(arg->flags, '-') && !ft_strchr2(arg->flags, '0'))
	{
		if (arg->precision == 1 && arg->precision_nb == 0)
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
	else if (ft_strchr2(arg->flags, '-'))
		int_output2(nb, arg, arg_len);
	else if (ft_strchr2(arg->flags, '0'))
		int_output3(nb, arg, arg_len);
	arg->print_count += arg_len;
	return (arg->print_count);
}

void	int_output1(intmax_t nb, t_arg *arg, int arg_len)
{
	intmax_t	pad_space_nb;
	intmax_t	pad_zero_nb;

	pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb >= pad_space_nb)
		{
			print_int_sign(arg);
			print_padded_char(pad_zero_nb, arg, '0');
		}
		if (pad_zero_nb < pad_space_nb)
		{
			if (ft_strchr2(arg->flags, '+') || ft_strchr2(arg->flags, ' ') || arg->neg_arg_int)
				print_padded_char(pad_space_nb - pad_zero_nb - 1, arg, ' ');
			else
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

	if (ft_strchr2(arg->flags, '+') || ft_strchr2(arg->flags, ' ') || arg->neg_arg_int)
		pad_space_nb = ft_max(arg->width_nb - arg_len - 1, 0);
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	print_int_sign(arg);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putnbr_intmax_t(nb);
	print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
}

void	int_output3(intmax_t nb, t_arg *arg, int arg_len)
{
	intmax_t	pad_zero_nb;

	if (arg->neg_arg_int)
	{
		pad_zero_nb = ft_max(arg->width_nb - arg_len - 1, 0);
		print_int_sign(arg);
	}
	else
	{
		if (ft_strchr2(arg->flags, '+') || ft_strchr2(arg->flags, ' '))
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
