# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzui <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/29 19:47:33 by dzui              #+#    #+#              #
#    Updated: 2017/10/31 15:48:52 by dzui             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C assembly
	make -C vm

clean:
	make clean -C vm
	make clean -C assembly

fclean:
	make fclean -C vm
	make fclean -C assembly

re:
	make re -C vm
	make re -C assembly
