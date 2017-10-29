# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozabara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/13 14:26:21 by ozabara           #+#    #+#              #
#    Updated: 2017/09/29 12:29:28 by ozabara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c \
		advance_itoa_functions.c \
		append.c \
		parse.c \
		setup.c \
		wchar_parse.c \
		handle_binary.c \
		handle_char.c \
		handle_decimal.c \
		handle_hex.c \
		handle_octal.c \
		handle_pct_and_errors.c \
		handle_precision.c \
		handle_ptr.c \
		handle_sign.c \
		handle_space.c \
		handle_string.c \
		handle_unsigned.c \
		handle_width.c

LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstiter.c ft_lstmap.c ft_abs.c get_next_line.c ft_strlenc.c ft_strndup.c \
ft_charindex.c ft_str_condition_fulfilling.c ft_strn_condition_fulfilling.c \
ft_isspace.c

FILE_SRCS = $(addprefix srcs/ft_printf/,$(FILES))

LIBFT_SRCS = $(addprefix srcs/libft/,$(LIBFT))

SRCS = $(FILE_SRCS) $(LIBFT_SRCS)

OBJ = $(SRCS:.c=.o)

HDR = -I./includes

.PHONY: all clean fclean re

all: $(NAME)

%.o:%.c
	@gcc $(CFLAGS) $(HDR) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf.a created"

clean:
	@/bin/rm -f $(OBJ)
	@echo ".o-files deleted"
	
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "libftprintf.a deleted"

re: fclean all
