# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkathlee <dkathlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 15:06:54 by dkathlee          #+#    #+#              #
#    Updated: 2020/02/26 15:19:55 by dkathlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCDIR = srcs/
INCDIR = includes/
OBJDIR = obj/

SRCS =	ft_ls.c

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -g

FTDIR = ft_printf/
FTLIB = $(addprefix $(FTDIR), libftprintf.a)
FTINC = -I $(FTDIR)/includes -I $(FTDIR)/libft/includes
FTLNK = -L $(FTDIR)

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FTLIB) $(FTLNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

.PHONY: clean fclean all re
