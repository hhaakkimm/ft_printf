/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_with_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:19:16 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/02 17:19:29 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*parse_width(int *width, va_list *args, char **str)
{
	if (**str == '*')
	{
		*width = va_arg(*args, int);
		(*str)++;
	}
	else 
		*width = try_get(str);
}

void	*parse_flags(params *val, char **str)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, **str))
	{
		if (ft_strchr(val->flags, **str) == NULL)
		{
			val->flags[i] = **str;
			i++;
		}
		(*str)++;
	}
	val->flags[i] = '\0';
}

char    *parse_arg(va_list args, params *val, char **str)
{
    parse_flags(val, str);
	parse_width(&(val->width), args, str);

	if (val->width < 0)
	{
		val->width *= (-1);
		val->move = -1;
	}
	if (ft_strchr(str, '.'))
	{
		(*str)++;
		parse_width(&(val->precision), args, str);
	}
	
}

int     handle(char **str, va_list args)
{
    params	val;
	int		T;

	T = 9;
    val.length = 0;
    val.type = 0;
	val.width = 0;
    val.value = "";
	while (T--)
		val.flags[T] = '\0';
	if (**str == '%')
	{
		(*str)++;
		if (*str != '\0')
		{
			*str = parse_arg(args, &val, str);
			if (**str != 0)
				(*str)++;
			return (print_arg(args, &val));
		}
	}
	return (0);
}