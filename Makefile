# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:45:49 by syamashi          #+#    #+#              #
#    Updated: 2021/03/22 14:54:06 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
PUSH_SWAP_DIR = "./push_swap"
CHECKER_DIR = "./checker_files"

all:
	make -C $(PUSH_SWAP_DIR) && cp $(PUSH_SWAP_DIR)/push_swap ./;
	make -C $(CHECKER_DIR) && cp $(CHECKER_DIR)/checker ./;

clean:
	make -C $(CHECKER_DIR) clean;
	make -C $(PUSH_SWAP_DIR) clean;

fclean:
	rm -f $(PUSH_SWAP);
	rm -f $(CHECKER);
	make -C $(CHECKER_DIR) fclean;
	make -C $(PUSH_SWAP_DIR) fclean;

$(PUSH_SWAP):
	make -C $(PUSH_SWAP_DIR);

$(CHECKER):
	make -C $(CHECKER_DIR);

re: fclean all

.PHONY: all clean fclean re push_swap checker
