# Nome dei programmi
NAME_CLIENT = client
NAME_SERVER = server

# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Cartelle del progetto
SRC_DIRS = . libft ft_printf
INCLUDES = -I includes -I libft -I ft_printf

# Trova tutti i file .c nelle directory specificate per libft e ft_printf
SRCS_LIBFT = $(wildcard libft/*.c)
SRCS_PRINTF = $(wildcard ft_printf/*.c)

# File oggetto da compilare
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

# Obiettivi: compilare client e server separatamente
all: $(NAME_CLIENT) $(NAME_SERVER)

# Compilazione del client
$(NAME_CLIENT): client.o $(OBJS_LIBFT) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) client.o $(OBJS_LIBFT) $(OBJS_PRINTF) -o $(NAME_CLIENT)

# Compilazione del server
$(NAME_SERVER): server.o $(OBJS_LIBFT) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) server.o $(OBJS_LIBFT) $(OBJS_PRINTF) -o $(NAME_SERVER)

# Compilazione dei file .c in .o per il client e il server
client.o: client.c
	$(CC) $(CFLAGS) $(INCLUDES) -c client.c -o client.o

server.o: server.c
	$(CC) $(CFLAGS) $(INCLUDES) -c server.c -o server.o

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS_LIBFT) $(OBJS_PRINTF) client.o server.o

# Pulizia completa
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

# Ricompila tutto da zero
re: fclean all

.PHONY: all clean fclean re
