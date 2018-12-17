#include "../includes/ft_printf.h"

void		hex_output1(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (ft_strchr2(arg->flags, '#'))
		pad_space_nb = ft_max(arg->width_nb - arg_len - 2, 0);
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->precision_nb - arg_len, 0);
	if (ft_strchr2(arg->flags, '#') && (pad_zero_nb >= pad_space_nb))
		print_hex_flag_hash(arg);
	if (pad_space_nb > 0 || pad_zero_nb > 0)
	{
		if (pad_zero_nb < pad_space_nb)
		{
			if (ft_strchr2(arg->flags, '#'))
			{
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
				print_hex_flag_hash(arg);
			}
			else
				print_padded_char(pad_space_nb - pad_zero_nb, arg, ' ');
		}
		print_padded_char(pad_zero_nb, arg, '0');
	}
	ft_putstr(hex_str);
}

void		hex_output2(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_space_nb;
	uintmax_t	pad_zero_nb;

	if (ft_strchr2(arg->flags, '#'))
	{
		pad_space_nb = ft_max(arg->width_nb - arg_len - 2, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_space_nb = ft_max(arg->width_nb - arg_len, 0);
	pad_zero_nb = ft_max(arg->width_nb - arg_len - 2, 0);
	print_padded_char(pad_zero_nb - pad_space_nb, arg, '0');
	ft_putstr(hex_str);
	print_padded_char(pad_space_nb, arg, ' ');
}

void		hex_output3(char *hex_str, t_arg *arg, int arg_len)
{
	uintmax_t	pad_zero_nb;

	if (ft_strchr2(arg->flags, '#'))
	{
		pad_zero_nb = ft_max(arg->width_nb - arg_len - 2, 0);
		print_hex_flag_hash(arg);
	}
	else
		pad_zero_nb = ft_max(arg->width_nb - arg_len, 0);
	print_padded_char(pad_zero_nb, arg, '0');
	ft_putstr(hex_str);
}

int			handle_hex(va_list list, t_arg *arg)
{
	uintmax_t	nb;
	int			i;
	char		*hex_str;
	int			arg_len;

	if (arg->precision || ft_strchr2(arg->flags, '-'))
	{
		i = -1;
		while (++i < 6)
			if (arg->flags[i] == '0')
				arg->flags[i] = 'x';
	}
	if ((nb = get_unsigned_type_by_length(list, arg)) == 0)
	{
		i = -1;
		while (++i < 6)
			if (arg->flags[i] == '#')
				arg->flags[i] = 'x';
	}
	hex_str = ft_itoa_base_uint(nb, 16, arg->conversion);
	arg_len = ft_strlen(hex_str);
	if (!ft_strchr2(arg->flags, '-') && !ft_strchr2(arg->flags, '0'))
	{
		if (arg->precision == 1 && arg->precision_nb == 0)
		{
			if (arg->width_nb)
				print_padded_char(arg->width_nb, arg, ' ');
			free(hex_str);
			return (arg->print_count);
		}
		hex_output1(hex_str, arg, arg_len);
	}
	else if (ft_strchr2(arg->flags, '-') || ft_strchr2(arg->flags, '0'))
		hex_helper(hex_str, arg, arg_len);
	free(hex_str);
	return (arg->print_count + arg_len);
}

void		hex_helper(char *hex_str, t_arg *arg, int arg_len)
{
	if (ft_strchr2(arg->flags, '-'))
		hex_output2(hex_str, arg, arg_len);
	else if (ft_strchr2(arg->flags, '0'))
		hex_output3(hex_str, arg, arg_len);
}
