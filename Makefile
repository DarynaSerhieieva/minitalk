CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
CLIENT_SRC = client.c
SERVER_SRC = server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
INCLUDES = ./includes
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(INCLUDES)

# Output files (client and server executables)
all: $(LIBFT) $(CLIENT) $(SERVER)

# Compile client
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

# Compile server
$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

# Compile object files for client
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT_INC)

# Compile libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make clean -C $(LIBFT_DIR)

# Clean object files and executables
fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make fclean -C $(LIBFT_DIR)

# Recompile everything
re: fclean all
