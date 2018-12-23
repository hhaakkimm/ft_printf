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
	float d = 5.23456;
	ft_printf("%.4d", d);
	ft_printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "HAKEEM", "ATA");
}
