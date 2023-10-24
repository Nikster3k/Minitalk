CLIENT = client
SERVER = server
LIBFT = printf/libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra

C_SRC = client.c
S_SRC = server.c

C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(C_OBJ)
	$(COMPILER) $(FLAGS) $(C_OBJ) $(LIBFT) -o $(CLIENT)

$(SERVER): $(LIBFT) $(S_OBJ)
	$(COMPILER) $(FLAGS) $(S_OBJ) $(LIBFT) -o $(SERVER)

bonus: all

$(LIBFT):
	(cd printf && make all)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	(cd printf && make clean)
	rm -f $(C_OBJ) $(S_OBJ)

fclean: clean
	(cd printf && make fclean)
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: clean fclean re bonus