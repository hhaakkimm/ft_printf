#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# define FLAGS "-0+ #"

typedef struct	s_arg
{
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_space;
	int			flag_plus;
	char		flags[6];
	int			field_width;
	int			width_nb;
	int			precision;
	int			precision_nb;
	enum		{null, h, hh, l, ll, j, z} length;
	char		conversion;
	int			print_count;
	int			neg_arg_int;
}				t_arg;

int     		ft_strchr2(char *s, char c);

int				handlers(char **format, va_list list, t_arg *arg);
size_t			ft_nbrlen(size_t nb);
int				solve_arg(char **format, va_list list, t_arg *sarg);
int				ft_solve_format(char *format, va_list list, size_t chars);
int				ft_printf(char *format, ...);
char			*parse_flag(char **format, t_arg *arg);
char			*parse_width(char **format, t_arg *arg, va_list list);
char			*parse_length(char **format, t_arg *arg);
char			*parse_conversion(char **format, t_arg *arg);
char			*parse_prescision(char **format, t_arg *arg, va_list list);
void			init(t_arg *arg);
void			print_struct(t_arg *arg);
void			print_padded_char(int padded_len, t_arg *arg, char c);
void			print_int_sign(t_arg *arg);
int				handle_int(va_list list, t_arg *arg);
void			int_output1(intmax_t nb, t_arg *arg, int arg_len);
void			int_output2(intmax_t nb, t_arg *arg, int arg_len);
void			int_output3(intmax_t nb, t_arg *arg, int arg_len);
int				int_output_helper(t_arg *arg, intmax_t nb, int arg_len);
int				handle_chr(va_list list, t_arg *arg);
int				handle_wchr(va_list list, t_arg *arg);
int				handle_str(va_list list, t_arg *arg);
void			str_output(va_list list, t_arg *arg);
void			str_output_helper(t_arg *arg, char *arg_str, int min_print, int arg_len);
int				handle_wstr(va_list list, t_arg *arg);
void			wstr_output(t_arg *arg, wchar_t *arg_wstr, int arg_len,
															int min_print);
char			*ft_itoa_base_uint(uintmax_t nb, uintmax_t base_nb, char c);
void			print_hex_flag_hash(t_arg *arg);
void			hex_output1(char *hex_str, t_arg *arg, int arg_len);
void			hex_output2(char *hex_str, t_arg *arg, int arg_len);
void			hex_output3(char *hex_str, t_arg *arg, int arg_len);
int				handle_hex(va_list list, t_arg *arg);
void			hex_helper(char *hex_str, t_arg *arg, int arg_len);
void			ptr_output1(char *address_str, t_arg *arg, int arg_len);
void			ptr_output2(char *address_str, t_arg *arg, int arg_len);
int				handle_ptr(va_list list, t_arg *arg);
void			oct_output1(char *oct_str, t_arg *arg, int arg_len);
void			oct_output2(char *oct_str, t_arg *arg, int arg_len);
void			oct_output3(char *oct_str, t_arg *arg, int arg_len);
int				handle_octal(va_list list, t_arg *arg);
void			oct_output_helper(char *oct_str, t_arg *arg, int arg_len);
void			unsigned_output1(char *unsigned_str, t_arg *arg, int arg_len);
void			unsigned_output2(char *unsigned_str, t_arg *arg, int arg_len);
void			unsigned_output3(char *unsigned_str, t_arg *arg, int arg_len);
int				handle_unsigned(va_list list, t_arg *arg);
int				handle_percent(va_list list, t_arg *arg);
uintmax_t		get_unsigned_type_by_length(va_list list, t_arg *arg);
intmax_t		get_int_type_by_length(va_list list, t_arg *arg);

# define BLACK		"\033[0;30m"
# define BLUE		"\033[0;34m"
# define CYAN		"\033[1;36m"
# define DARKYELLOW	"\033[0;33m"
# define GREEN		"\033[0;32m"
# define GREY		"\033[1;30m"
# define LAVENDER	"\033[1;35m"
# define LIGHTBLUE	"\033[0;36m"
# define LIGHTGREY	"\033[0;37m"
# define LIME		"\033[1;32m"
# define MAGENTA	"\033[0;35m"
# define PINK		"\033[1;31m"
# define PURPLE		"\033[1;34m"
# define RED		"\033[0;31m"
# define UNDERLINE	"\033[4m"
# define WHITE		"\033[1;37m"
# define YELLOW		"\033[1;33m"
# define RESET		"\033[0m"

#endif
