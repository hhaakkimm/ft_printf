#include "../includes/ft_printf.h"

void	init(t_arg *arg)
{
	int i;
	
	i = 0;
	while (i++ < 6)
		arg->flags[i] = '\0';
	arg->field_width = 0;
	arg->width_nb = 0;
	arg->precision = 0;
	arg->precision_nb = 0;
	arg->conversion = 0;
	arg->print_count = 0;
	arg->neg_arg_int = 0;
}

void	print_int_sign(t_arg *arg)
{
	if ((ft_strchr2(arg->flags, '+') || ft_strchr2(arg->flags, ' ')) && arg->neg_arg_int == 0)
	{
		if (ft_strchr2(arg->flags, '+'))
		{
			write(1, "+", 1);
			arg->print_count++;
		}
		else if (ft_strchr2(arg->flags, ' '))
		{
			write(1, " ", 1);
			arg->print_count++;
		}
	}
	if (arg->neg_arg_int)
	{
		write(1, "-", 1);
		arg->print_count++;
	}
}

void	print_padded_char(int padded_len, t_arg *arg, char c)
{
	int	i;

	i = 0;
	while (i < padded_len)
	{
		ft_putchar(c);
		arg->print_count++;
		i++;
	}
}

void	print_hex_flag_hash(t_arg *arg)
{
	if (arg->conversion == 'x' || arg->conversion == 'p')
	{
		write(1, "0x", 2);
		arg->print_count += 2;
	}
	else if (arg->conversion == 'X')
	{
		write(1, "0X", 2);
		arg->print_count += 2;
	}
	else if (arg->conversion == 'o' || arg->conversion == 'O')
	{
		write(1, "0", 1);
		arg->print_count++;
	}
}
