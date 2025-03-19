NAME	=	libft.a

CFILES	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c 		\
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c 				\
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c 	\
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c 	\
			ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c 	\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c

LIB 	= 	libft.h

Ofiles	=	$(CFILES:.c=.o)

BonusC	=	ft_lstnew.c ft_lstadd_front.c	\
			ft_lstsize.c ft_lstlast.c 		\
			ft_lstadd_back.c ft_lstdelone.c

BonusO	=	$(BonusC:.c=.o)

FLAGS	= 	-Wall -Werror -Wextra

AR		=	ar -rcs
RM		= 	rm -f

%.o: %.c
		cc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(Ofiles)
		$(AR) $@ $^

bonus: $(BonusO)
		$(AR) $(NAME) $^

$(BonusO):
		cc $(FLAGS) -c $(@:.o=.c) -o $@

clean:
		$(RM) $(Ofiles) $(BonusO)

fclean: clean
		$(RM) $(NAME)

re: fclean all

exec: re bonus
		gcc $(FLAGS) main.c $(NAME) -lbsd && ./a.out | cat -e

.PHONY: all clean fclean re exec bonus
