# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozabara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 16:24:09 by ozabara           #+#    #+#              #
#    Updated: 2017/10/29 21:08:49 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = ../asm

FLAGS =	-Wall -Wextra -Werror

FILES = cw_assembly_data.c \
		cw_create_param_byte.c \
		cw_display_details.c \
		cw_display_hex.c \
		cw_free_and_exit.c \
		cw_get_program_data.c \
		cw_make_binary.c \
		cw_open_in.c \
		cw_parse_add_instruction.c \
		cw_parse_additional_functions.c \
		cw_parse_additional_functions2.c \
		cw_parse_additional_functions3.c \
		cw_parse_arg_dir_and_ind.c \
		cw_parse_check_header.c \
		cw_parse_eval_expr.c \
		cw_parse_get_args.c \
		cw_parse_get_code.c \
		cw_parse_in.c \
		cw_parse_name_and_comment.c \
		cw_parse_save_args.c \
		cw_parse_save_code.c \
		cw_parse_struct.c \
		cw_parse_tags.c \
		cw_parse_validate_args.c \
		cw_reverse_binary.c \
		cw_reverse_header.c \
		cw_reverse_instructions.c \
		cw_set_tag_value.c \
		cw_write_binary.c \
		cw_write_byte.c \
		cw_write_header.c \
		main.c \
		op.c

SRC = $(addprefix srcs/, $(FILES))
LIBFT = libft/libftprintf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I includes/ -o $@ -c $<

$(NAME): $(OBJ)
	@echo "Compiling libftprintf ..."
	@$(MAKE) -C ./libft
	@$(MAKE) clean -C ./libft
	@echo "Compiling asm ..."
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "asm is compiled"

clean:
	@rm -f $(OBJ)
	@echo ".o-files deleted"

fclean:
	@make clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "asm deleted"

re:
	@make fclean
	@make all
