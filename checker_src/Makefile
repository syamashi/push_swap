# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:54:21 by syamashi          #+#    #+#              #
#    Updated: 2021/03/31 12:52:58 by syamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
SRCDIR = ./
SRCNAMES = $(shell echo *.c)
SRCS = $(addprefix $(SRCDIR), $(SRCNAMES))

OBJDIR = ./obj/
OBJS = $(SRCNAMES:%.c=$(OBJDIR)%.o)

LIBDIR = ../libft

UTILDIR = ../util

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(OBJDIR) $(NAME)

$(OBJDIR) :
	mkdir -p obj

$(OBJDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	make -C $(LIBDIR)
	make -C $(UTILDIR)
#	$(CC) $(CFLAGS) -I../includes -o $@ $^ -L $(LIBDIR) -L $(UTILDIR) -lutil -lft
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -L $(UTILDIR) -lutil -lft -o $@ $^

clean :
	make clean -C $(LIBDIR)
	make clean -C $(UTILDIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBDIR)
	make fclean -C $(UTILDIR)
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re
