NAME = so_long

SRC = so_long.c

INCLUDES = -I minilibx-linux
LIBS = -L minilibx-linux -lmlx -lXext -lX11 -lbsd

CC = gcc
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(INCLUDES) $(LIBS)

all: $(NAME)

clean:
	# Non è necessario alcun comando per la pulizia dei file temporanei, poiché non ce ne sono

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re