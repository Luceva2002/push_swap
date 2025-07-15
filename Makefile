# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 19:30:00 by luevange          #+#    #+#              #
#    Updated: 2025/07/15 18:04:43 by luevange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRCDIR = .
UTILSDIR = utils
OBJDIR = obj

SRCS = \
	$(SRCDIR)/push_swap.c \
	$(SRCDIR)/push.c \
	$(SRCDIR)/swap.c \
	$(SRCDIR)/rotate.c \
	$(SRCDIR)/reverse_rotate.c \
	$(SRCDIR)/radix.c \
	$(SRCDIR)/index.c \
	$(SRCDIR)/sort_small.c \
	$(SRCDIR)/free.c \
	$(SRCDIR)/edge_cases.c \
	$(SRCDIR)/stack.c \
	$(UTILSDIR)/ft_atoi.c \
	$(UTILSDIR)/ft_isdigit.c \
	$(UTILSDIR)/ft_split.c \
	$(UTILSDIR)/ft_putstr_fd.c \
	$(UTILSDIR)/ft_strlcpy.c \
	$(UTILSDIR)/ft_strlen.c \

OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
