NAME = minitalk

CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes/
PRINTF = ./ft_printf/
PRINTF_A = ./ft_printf/libftprintf.a

all: server client
printf:
	make -C $(PRINTF)
	cp $(PRINTF_A) $(NAME)
server: printf
	cc  $(CFLAGS) -g srcs/server.c $(PRINTF_A) -o server

client: printf
	cc  $(CFLAGS) -g srcs/client.c $(PRINTF_A) -o client


clean:
	make clean -C $(PRINTF)

fclean: clean
	rm -rf server client

re: fclean all