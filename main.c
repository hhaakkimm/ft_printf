/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:49:37 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/12/22 18:59:08 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"


int main()
{
	double d = 10.1232;
	int dd = 111;
	//ft_printf("%d\n", dd);
	//ft_printf("%c\n", 'T');
	ft_printf("%f\n", d);
	//printf("%f", d);
}
