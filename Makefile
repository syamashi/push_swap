# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:45:49 by syamashi          #+#    #+#              #
#    Updated: 2021/04/03 12:44:50 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
PUSH_SWAP_DIR = ./push_swap_src
CHECKER_DIR = ./checker_src

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
	rm -f $(PUSH_SWAP)
	rm -f $(CHECKER)

re: fclean all

bonus : all

.PHONY: all clean fclean re bonus
