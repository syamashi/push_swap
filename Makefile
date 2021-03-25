# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:45:49 by syamashi          #+#    #+#              #
#    Updated: 2021/03/25 16:37:12 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checkers
PUSH_SWAP_DIR = ./push_swaps
CHECKER_DIR = ./checkers

all:
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(PUSH_SWAP) ./
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;

re: fclean all

.PHONY: all clean fclean re
