# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 19:47:33 by dzui              #+#    #+#              #
#    Updated: 2017/10/29 21:07:36 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEV = corewar

SRCV = vm/ft_add.c\
	   vm/ft_aff.c\
	   vm/ft_and.c\
	   vm/ft_assign_vm.c\
	   vm/ft_champ_instr.c\
	   vm/ft_champions.c\
	   vm/ft_fork.c\
	   vm/ft_hex_to_dec.c\
	   vm/ft_ld.c\
	   vm/ft_ldi.c\
	   vm/ft_lfork.c\
	   vm/ft_live.c\
	   vm/ft_lld.c\
	   vm/ft_lldi.c\
	   vm/ft_op.c\
	   vm/ft_or.c\
	   vm/ft_other_tools.c\
	   vm/ft_print_information.c\
	   vm/ft_process.c\
	   vm/ft_process_args.c\
	   vm/ft_process_instructions.c\
	   vm/ft_read_instr_args.c\
	   vm/ft_run_vm.c\
	   vm/ft_run_vm_2.c\
	   vm/ft_st.c\
	   vm/ft_sti.c\
	   vm/ft_sub.c\
	   vm/ft_visual.c\
	   vm/ft_visual_2.c\
	   vm/ft_visual_3.c\
	   vm/ft_visual_4.c\
	   vm/ft_xor.c\
	   vm/ft_zjmp.c\
	   vm/main.c\

OBJV = $(SRCV:.c=.o)

HEADERV = vm/vm.h\
		  vm/op.h\

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror -c

all: $(NAMEV)

$(NAMEV): $(OBJV)
	make -C assembly
	make -C libft
	gcc $(FLAGS) $(SRCV)
	gcc -o $(NAMEV) $(LIB) $(OBJV) -lncurses

$(RECPR):
	make -C libft
	make -C assembly

clean: ft_add.o\
	   ft_aff.o\
	   ft_and.o\
	   ft_assign_vm.o\
	   ft_champ_instr.o\
	   ft_champions.o\
	   ft_fork.o\
	   ft_hex_to_dec.o\
	   ft_ld.o\
	   ft_ldi.o\
	   ft_lfork.o\
	   ft_live.o\
	   ft_lld.o\
	   ft_lldi.o\
	   ft_op.o\
	   ft_or.o\
	   ft_other_tools.o\
	   ft_print_information.o\
	   ft_process.o\
	   ft_process_args.o\
	   ft_process_instructions.o\
	   ft_read_instr_args.o\
	   ft_run_vm.o\
	   ft_run_vm_2.o\
	   ft_st.o\
	   ft_sti.o\
	   ft_sub.o\
	   ft_visual.o\
	   ft_visual_2.o\
	   ft_visual_3.o\
	   ft_visual_4.o\
	   ft_xor.o\
	   ft_zjmp.o\
	   main.o\

	rm -f $(OBJV)
	make clean -C libft
	make clean -C assembly

fclean: clean 
	make fclean -C libft
	make fclean -C assembly
	rm -f $(NAMEV)

re:	fclean all
	make re -C libft
	make re -C assembly
