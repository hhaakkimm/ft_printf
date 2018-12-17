MAKE = make -C
NAME = libftprintf.a
LIB = libft/
FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = -I /includes

CFILES =		src/redirection.c\
				src/parse.c\
				src/ft_strchr2.c\
				src/ft_printf.c\
				src/initial_print.c\
				src/handle_int.c\
				src/handle_char.c\
				src/handle_wchar.c\
				src/handle_str.c\
				src/handle_wstr.c\
				src/handle_hex.c\
				ft_putstring.c\
				src/handle_ptr.c\
				src/handle_octal.c\
				src/handle_unsigned.c\
				src/handle_escape.c\
				src/get_int_type.c

LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)
OBJ_DIR = objects

DOBJS = $(CFILES:.c = .o)
all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(FLAGS) -c $(CFILES) $(Header)
	@cp libft/libft.a $(NAME)
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)

clean:
	@$(LIBC)
	@/bin/rm -rf *.o

fclean:
	@$(LIBF)
	@/bin/rm -f $(NAME) *.a
	@/bin/rm -rf *.o
	@rm -rf $(NAME)
	@rm -f $(DNAME)

re: fclean all

.PHONY: all clean fclean re 
