/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stuff_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 05:02:15 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/17 05:02:28 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putwstr(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i]);
		i++;
	}
}

void		ft_putnwstr(wchar_t *wstr, size_t n)
{
	if (!wstr)
		return ;
	if (ft_wstrlen(wstr) >= n)
		write(1, wstr, n);
	else
		return ;
}

char		*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}
