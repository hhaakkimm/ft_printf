# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 19:23:16 by aabdrakh          #+#    #+#              #
#    Updated: 2018/12/20 19:34:01 by aabdrakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src/redirection.c src/parse.c src/ft_strchr2.c src/ft_printf.c
SRC += src/initial_print.c src/handle_int.c src/handle_char.c
SRC += src/handle_wchar.c src/handle_str.c src/handle_wstr.c
SRC += src/handle_hex.c src/ft_putstring.c src/handle_ptr.c src/get_int_type.c
SRC += src/handle_octal.c src/handle_unsigned.c src/handle_escape.c src/handle_float.c

OBJ = *.o

INC = -I libft/ -I includes/

LIBFT =	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc -c -Wall -Wextra -Werror $(INC) -c $^

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean
