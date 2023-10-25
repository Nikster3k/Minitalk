CLIENT = client
SERVER = server
CLIENT_BON = client_bonus
SERVER_BON = server_bonus
LIBFT = printf/libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra -g

C_SRC = client.c
S_SRC = server.c

CB_SRC = client_bonus.c
SB_SRC = server_bonus.c

C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

CB_OBJ = $(CB_SRC:.c=.o)
SB_OBJ = $(SB_SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) $(C_OBJ)
	$(COMPILER) $(C_OBJ) $(FLAGS) $(LIBFT) -o $(CLIENT)

$(SERVER): $(LIBFT) $(S_OBJ)
	$(COMPILER) $(S_OBJ) $(FLAGS) $(LIBFT) -o $(SERVER)

$(CLIENT_BON): $(LIBFT) $(CB_OBJ)
	$(COMPILER) $(CB_OBJ) $(FLAGS) $(LIBFT) -o $(CLIENT_BON)

$(SERVER_BON): $(LIBFT) $(SB_OBJ)
	$(COMPILER) $(SB_OBJ) $(FLAGS) $(LIBFT) -o $(SERVER_BON)

bonus: $(CLIENT_BON) $(SERVER_BON)

$(LIBFT):
	(cd printf && make all)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	(cd printf && make clean)
	rm -f $(C_OBJ) $(S_OBJ) $(CB_OBJ) $(SB_OBJ)

fclean: clean
	(cd printf && make fclean)
	rm -f $(SERVER) $(CLIENT) $(SERVER_BON) $(CLIENT_BON)

re: fclean all

.PHONY: clean fclean re bonus