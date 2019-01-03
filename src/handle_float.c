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
	f->precision = (f->precision != 0) ? f->precision : 6;
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
	//printf("%Lf fourth\n", n);
	dec = ft_itoa((long long int)n);
	len = ft_strlen(dec);
	dst = ft_strnew(sign + len + 1 + ((f->precision > 0) ? f->precision : 0));
	pos = sign;
	ft_strcpy(dst + pos, dec);
	pos += len;
	if (f->precision > 0)
		dst[pos++] = '.';
	while (pos <= len + sign + ((f->precision > 0) ? f->precision : 0))
	{
		dst[pos++] = ((unsigned long long int)(n * 10) % 10) + '0';
		n *= 10;
	}
	if (sign)
		dst[0] = '-';
	f->print_count = pos;
	return (dst);
}

char		*convert_float_nbr(long double p, t_arg *f)
{
	char	*str;

	str = NULL;
	//printf("%Lf second\n", p);
	str = ft_ftoa(p, f);
	//printf("%s third\n", str);
	return (str);
}

int		handle_float(va_list list, t_arg *arg)
{
	double	n;

	if (arg->length == ll)
		n = (long double)va_arg(list, long double);
	else
		n = (double)va_arg(list, double);
	//printf("%f inital\n", n);
	ft_putstr(convert_float_nbr(n, arg));
	return (arg->print_count);
}