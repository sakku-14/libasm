# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 14:01:56 by ysakuma           #+#    #+#              #
#    Updated: 2021/03/25 11:35:38 by ysakuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
TEST	= test

CC		= gcc
NA		= nasm
NFLAGS	= -f macho64
FLAGS	= -Wall -Wextra -Werror

SRCS	= ft_strlen.s \
		  ft_strcpy.s \
		  ft_strcmp.s \
		  ft_write.s \
		  ft_read.s \
		  ft_strdup.s
OBJS	= $(SRCS:.s=.o)

.s.o:
	$(NA) $(NFLAGS) $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean $(NAME)

test:
	gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
	./$(TEST)

.PHONY: all clean fclean re test
