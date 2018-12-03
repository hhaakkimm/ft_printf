/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:12:08 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/02 16:12:10 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putstring(char *str, size_t n)
{
    int x;
    
    x = (ft_strlen(str) < n) ? ft_strlen(str) : n;
    write(1, str, x);
}

int		try_get(char **str)
{
	int x;

	x = 0;
	while (ft_isdigit(**str))
	{
		x = x * 10 + (**str - '0');
		(*str)++;
	}
	return (x);
}