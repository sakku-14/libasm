NAME	= libasm.a
TEST	= test

CC		= gcc
NA		= nasm
NFLAGS	= -f macho64
FLAGS	= -Wall -Wextra -Werror

SRCS	= ft_strlen.s
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

test: $(NAME)
	gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
	./$(TEST) < Makefile

.PHONY: clean fclean re test
