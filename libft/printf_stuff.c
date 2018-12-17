/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 05:01:58 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/17 05:02:09 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_uint(uintmax_t nb, uintmax_t base_nb, char c)
{
	char	*result;
	char	*base;
	int		i;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	if (base_nb < 2 || 16 < base_nb)
		return (NULL);
	result = ft_memalloc(sizeof(char) * 35);
	while (base_nb <= nb)
	{
		result[i++] = base[nb % base_nb];
		nb = nb / base_nb;
	}
	if (base_nb > nb)
		result[i++] = base[nb];
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}

void		ft_putnbr_intmax_t(intmax_t n)
{
	if (n < 0)
		ft_putnbr_uintmax_t(-n);
	else if (n >= 10)
	{
		ft_putnbr_intmax_t(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

void		ft_putnbr_uintmax_t(uintmax_t n)
{
	if (n >= 10)
	{
		ft_putnbr_uintmax_t(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}


void	ft_putnstr(char *str, size_t n)
{
	if (!str)
		return ;
	if (ft_strlen(str) >= n)
		write(1, str, n);
	else
		return ;
}

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}
