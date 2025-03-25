# Nome dei programmi
NAME_CLIENT = client
NAME_SERVER = server

# Compilatore e flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Cartelle del progetto
SRC_DIRS = . includes/libft includes/ft_printf
INCLUDES = -I includes -I includes/libft -I includes/ft_printf

# Trova tutti i file .c nelle directory specificate
SRCS_LIBFT = $(wildcard includes/libft/*.c)
SRCS_PRINTF = $(wildcard includes/ft_printf/*.c)
SRCS_MAIN = client.c server.c

# File oggetto da compilare
OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
OBJS_MAIN = $(SRCS_MAIN:.c=.o)

# Obiettivo principale
all: $(NAME_CLIENT) $(NAME_SERVER)

# Compilazione delle librerie se hanno un Makefile
includes/libft/libft.a:
	@make -C includes/libft

includes/ft_printf/libftprintf.a:
	@make -C includes/ft_printf

# Compilazione del client
$(NAME_CLIENT): client.o includes/libft/libft.a includes/ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(INCLUDES) client.o -Lincludes/libft -lft -Lincludes/ft_printf -lftprintf -o $(NAME_CLIENT)

# Compilazione del server
$(NAME_SERVER): server.o includes/libft/libft.a includes/ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(INCLUDES) server.o -Lincludes/libft -lft -Lincludes/ft_printf -lftprintf -o $(NAME_SERVER)

# Compilazione dei file .c in .o per il client e il server
client.o: client.c
	$(CC) $(CFLAGS) $(INCLUDES) -c client.c -o client.o

server.o: server.c
	$(CC) $(CFLAGS) $(INCLUDES) -c server.c -o server.o

# Pulizia dei file oggetto
clean:
	rm -f $(OBJS_MAIN) $(OBJS_LIBFT) $(OBJS_PRINTF)
	make -C includes/libft clean
	make -C includes/ft_printf clean

# Pulizia completa
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C includes/libft fclean
	make -C includes/ft_printf fclean

# Ricompila tutto da zero
re: fclean all

.PHONY: all clean fclean re