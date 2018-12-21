/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:26:24 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/20 19:26:25 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		solve_arg(char **format, va_list list, t_arg *arg)
{
	int		nb_printout;

	init(arg);
	nb_printout = 0;
	if (**format == '\0')
		return (0);
	while (**format)
	{
		if ((parse_flag(format, arg)) == NULL)
			return (-1);
		if ((parse_width(format, arg, list)) == NULL)
			return (-1);
		if ((parse_prescision(format, arg, list)) == NULL)
			return (-1);
		if ((parse_length(format, arg)) == NULL)
			return (-1);
		if ((nb_printout = handlers(format, list, arg)) >= 0)
			break ;
	}
	return (nb_printout);
}

int		ft_solve_format(char *format, va_list list, size_t chars)
{
	t_arg	arg;
	char	*next_arg;
	int		arg_printout;

	if (!*format)
		return (chars);
	if (!(next_arg = ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return (chars + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_solve_format(next_arg, list, chars + (next_arg - format)));
	}
	else
	{
		format++;
		if ((arg_printout = solve_arg((char **)&format, list, &arg)) == -1)
			return (-1);
		return (ft_solve_format(format, list, chars + arg_printout));
	}
	return (arg_printout);
}

int		ft_printf(char *format, ...)
{
	va_list	list;
	int		ans;

	va_start(list, format);
	ans = ft_solve_format(format, list, 0);
	va_end(list);
	return (ans);
}
