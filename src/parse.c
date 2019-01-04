/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:28:36 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:28:37 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_flag(char **format, t_arg *arg)
{
	int i;

	i = 0;
	if (ft_chr2(FLAGS, **format))
	{
		while (ft_chr2(FLAGS, **format))
		{
			arg->flags[i] = **format;
			i++;
			(*format)++;
		}
	}
	return (*format);
}

char	*parse_width(char **format, t_arg *arg, va_list list)
{
	int	int_arg;

	while (**format == '*' || ft_isdigit(**format))
	{
		arg->field_width = 1;
		if (**format == '*')
		{
			if ((int_arg = va_arg(list, int)) < 0)
			{
				if (!ft_chr2(arg->flags, '-'))
					arg->flags[ft_strlen(arg->flags)] = '-';
				arg->width_nb = -int_arg;
			}
			else
				arg->width_nb = int_arg;
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
				arg->width_nb = arg->width_nb * 10 + *(*format)++ - '0';
		}
	}
	return (*format);
}

char	*parse_prescision(char **format, t_arg *arg, va_list list)
{
	int	int_prec;

	if (**format == '.')
	{
		(*format)++;
		arg->precision = 1;
		if (**format == '*')
		{
			if ((int_prec = va_arg(list, int)) >= 0)
				arg->pre_nb = int_prec;
			else
			{
				arg->precision = 0;
				arg->field_width = 1;
				arg->width_nb = -int_prec;
			}
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			while (ft_isdigit(**format))
				arg->pre_nb = arg->pre_nb * 10 + *(*format)++ - '0';
		}
	}
	return (*format);
}

char	*parse_length(char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l')
	{
		if (**format == 'h')
			arg->length = h;
		else if (**format == 'l')
			arg->length = l;
		return ((*format)++);
	}
	else
		return (*format);
}

char	*parse_conversion(char **format, t_arg *arg)
{
	if (ft_chr2("sSpdDioOuUxXcCfF%", **format))
	{
		arg->conversion = **format;
		(*format)++;
	}
	return (*format);
}
