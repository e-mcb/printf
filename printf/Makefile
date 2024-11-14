SRC =	ft_printf.c \
		printhex.c \
		printnbr.c \
		printptr.c \
		printstr.c \
		printuint.c \

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJFILES = $(SRC:.c=.o)

AR = ar -rc
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES)
	ranlib $(NAME)

clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)