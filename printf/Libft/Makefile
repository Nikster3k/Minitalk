NAME = libft.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra #-std=c99

BONUS_SRCS = ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \

MANDATORY_SRCS = ft_atoi.c ft_memset.c ft_strlcpy.c \
				ft_bzero.c ft_putchar_fd.c ft_strlen.c \
				ft_calloc.c ft_putendl_fd.c ft_strmapi.c \
				ft_isalnum.c ft_putnbr_fd.c ft_strncmp.c \
				ft_isalpha.c ft_putstr_fd.c ft_strnstr.c \
				ft_isascii.c  ft_split.c ft_strrchr.c \
				ft_isdigit.c  ft_strchr.c ft_strtrim.c \
				ft_isprint.c ft_memchr.c ft_strdup.c ft_substr.c \
				ft_itoa.c ft_memcmp.c ft_striteri.c ft_tolower.c \
				ft_memcpy.c ft_strjoin.c ft_toupper.c \
				ft_memmove.c ft_strlcat.c \

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	ar rcs $@ $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
