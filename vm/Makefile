# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozabara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 16:24:09 by ozabara           #+#    #+#              #
#    Updated: 2017/10/31 15:39:21 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = ../corewar

FLAGS =	-Wall -Wextra -Werror

FILES = ft_add.c \
		ft_aff.c \
		ft_and.c \
		ft_assign_vm.c \
		ft_champ_instr.c \
		ft_champions.c \
		ft_fork.c \
		ft_hex_to_dec.c \
		ft_ld.c \
		ft_ldi.c \
		ft_lfork.c \
		ft_live.c \
		ft_lld.c \
		ft_lldi.c \
		ft_op.c \
		ft_or.c \
		ft_other_tools.c \
		ft_print_information.c \
		ft_process.c \
		ft_process_args.c \
		ft_process_instructions.c \
		ft_read_instr_args.c \
		ft_run_vm.c \
		ft_run_vm_2.c \
		ft_st.c \
		ft_sti.c \
		ft_sub.c \
		ft_visual.c \
		ft_visual_2.c \
		ft_visual_3.c \
		ft_visual_4.c \
		ft_xor.c \
		ft_zjmp.c \
		main.c \
		
SRC = $(addprefix srcs/, $(FILES))
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -I includes/ -o $@ -c $<

$(NAME): $(OBJ)
	@echo "Compiling libft ..."
	@$(MAKE) -C ./libft
	@$(MAKE) clean -C ./libft
	@echo "Compiling corewar	..."
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) -lncurses
	@echo "corewar is compiled"

clean:
	@rm -f $(OBJ)
	@echo ".o-files deleted"

fclean:
	@make clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C ./libft
	@echo "corewar deleted"

re:
	@make fclean
	@make all
