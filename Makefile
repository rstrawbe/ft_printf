# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 22:09:46 by rstrawbe          #+#    #+#              #
#    Updated: 2020/07/30 22:23:56 by rstrawbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTFH = ft_printf.h

PRINTFSO = libftprintf.so

FLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_digit_len.c srcs/ft_print_char.c srcs/ft_print_str.c srcs/ft_printf.c srcs/ft_putnbr.c \
	  srcs/ft_strlen.c srcs/ft_to_base.c srcs/get_digit_while_int.c srcs/is_digit.c srcs/is_flag.c print_sign.c \
	  srcs/render_arg_addr.c srcs/render_arg_base16.c srcs/render_arg_char.c srcs/render_arg_int.c \
	  srcs/render_arg_percent.c srcs/render_arg_string.c srcs/render_arg_uint.c srcs/render_argument.c \
	  srcs/set_fields.c srcs/specifier_clear.c srcs/specifier_init.c srcs/specifier_print.c srcs/to_base_cnt.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(PRINTFH)
	gcc $(FLAGS) -c $< -o $@

so:
	gcc -c -fPIC $(SRC)
	gcc -shared -o $(PRINTFSO) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) $(PRINTFSO)

re: fclean all
.PHONY: all clean fclean re bonus so
