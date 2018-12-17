/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:03:42 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/08 16:03:44 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strchr2(char *s, char c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
        {
            return (i);
        }
        i++;
    }
    return (-1);
}