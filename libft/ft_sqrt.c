/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 01:10:11 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/11/07 01:14:45 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int x)
{
	int l;
	int r;
	int m;

	l = 1;
	r = x;
	while (l < r)
	{
		m = (l + r) / 2;
		if (m * m < x)
			l = m + 1;
		else
			r = m;
	}
	return (r);
}
