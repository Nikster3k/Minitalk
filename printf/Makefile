NAME = libftprintf.a
LIBFT = libft.a
LIBFT_PATH = ./Libft/
COMPILER = cc
FLAGS = -Wall -Werror -Wextra 

ALL_SRCS = ft_printf.c ft_putnbr_base.c ft_putnbr_cnt.c \
		ft_putunbr_cnt.c ft_putstr_cnt.c \

ALL_OBJS = $(ALL_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(LIBFT) $(ALL_OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

$(LIBFT):
	(cd $(LIBFT_PATH) && make all bonus && mv $(LIBFT) $(NAME) && mv $(NAME) ..)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)
	(cd $(LIBFT_PATH) && make clean)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
