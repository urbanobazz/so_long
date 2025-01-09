NAME = libft.a
CC = cc
CCAR = ar rcs
CFLAGS = -Wall -Wextra -Werror
HFILE = libft.h
OBJS = ${SRC:.c=.o}
SRC =	ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_memset.c\
		ft_strdup.c\
		ft_strlen.c\
		ft_strncmp.c\
		ft_strjoin.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strchr.c\
		ft_memcpy.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		./get_next_line/get_next_line.c\
		./ft_printf/ft_printf.c\
		./ft_printf/ft_printf_utils.c\
		./ft_printf/ft_putsth.c\


all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HFILE)

$(NAME): $(OBJS)
	@$(CCAR) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
