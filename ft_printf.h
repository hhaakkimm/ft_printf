/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:40:14 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/11/24 18:40:15 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
 #define FT_PRINTF

#include "libft/libft.h"
#include <stdarg.h>

#define FLAGS "-0+ #"

typedef struct param{
	int		length;
	int		precision;
	int		move;
	int		type;
	int		width;
	char	*value;
	char	flags[10];
}   params;

int    ft_printf(char *type, ...);
void   ft_putstring(char *str, size_t n);
int    try_get(char **str);

#endif