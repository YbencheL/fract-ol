CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRC = fractol.c utils.c logic.c utilities.c src/ft_strlen.c src/ft_strncmp.c src/ft_atoi.c src/ft_atof.c \
	  ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_putnbr.c ft_printf/ft_handle_percent.c \
       ft_printf/ft_intlen.c ft_printf/ft_puthexo.c ft_printf/ft_putptr.c \
       ft_printf/ft_printf.c ft_printf/ft_putnbr_unsigned.c ft_printf/ft_intlen_base.c
OBJ = $(SRC:.c=.o)

all: fractol

fractol: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o fractol

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f fractol

re: fclean all