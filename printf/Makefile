NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rcs
MAKE = make -C
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_print_c.c ft_print_n.c ft_print_p.c ft_print_s.c \
			ft_print_u.c ft_print_x.c ft_printf.c

S_OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

$(NAME): $(S_OBJS)
	$(MAKE) $(LIBFT_DIR) all
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(S_OBJS)

clean:
	$(MAKE) $(LIBFT_DIR) clean
	$(RM) $(S_OBJS)

fclean: clean
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
