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

#include "includes/ft_printf.h"

void ft_putstring(char *str, size_t n)
{
    int x;
    
    x = (ft_strlen(str) < n) ? ft_strlen(str) : n;
    write(1, str, x);
}

size_t		ft_nbrlen(size_t nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}