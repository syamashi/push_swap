# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:45:49 by syamashi          #+#    #+#              #
#    Updated: 2021/03/26 21:45:54 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
PUSH_SWAP_DIR = ./push_swap_src
PUSH_SWAP_SRCS = $(shell echo $(PUSH_SWAP_DIR)/*.c)

CHECKER = checker
CHECKER_DIR = ./checker_src
CHECKER_SRCS = $(shell echo $(CHECKER_DIR)/*.c)

LIBDIR = ./libft

UTILDIR = ./util

NAME = $(PUSH_SWAP) $(CHECKER)

OBJDIR = ./obj/
PUSH_SWAP_OBJS = $(PUSH_SWAP_DIR:%.c=$(OBJDIR)%.o)
CHECKER_OBJS = $(CHECKER_DIR:%.c=$(OBJDIR)%.o)
OBJS = $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

SRCDIR = $(PUSH_SWAP_DIR) $(CHECKER_DIR)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	mkdir -p obj

all: $(OBJDIR) $(PUSH_SWAP)

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make -C $(LIBDIR)
	make -C $(UTILDIR)
#	$(CC) $(CFLAGS) -I../includes -o $@ $^ -L $(LIBDIR) -L $(UTILDIR) -lutil -lft
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -L $(UTILDIR) -lutil -lft -o $(PUSH_SWAP) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -L $(UTILDIR) -lutil -lft -o $(CHECKER) $(CHECKER_OBJS)

clean:
	make clean -C $(LIBDIR)
	make clean -C $(UTILDIR)
	rm -f $(POBJS) $(COBJS)

fclean:
	make fclean -C $(LIBDIR)
	make fclean -C $(UTILDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
