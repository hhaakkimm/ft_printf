/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:44:25 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/11/24 18:44:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	run(char *type, va_list *args)
{
	char	*str;
	char	*start;
	int		len;

	str = (char *)type;
	start = str;
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_putstring(start, str - start);
			len += handle(&str, args);
			start = str;
		}
		else
		{
			len++;
			str++;
		}
		
	}
	ft_putstring(start, str - start);
	return (len);
}

int		ft_printf(char *type, ...)
{
	va_list	list;
	int		answer;

	va_start(list, type);
	answer = run(type, list);
	va_end(list);
	return (answer);
}

int		main()
{
	ft_printf("%d%f  %c", 777, 2, 3);
}