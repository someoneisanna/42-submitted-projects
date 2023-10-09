NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
MAKE = make -C

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX = -L ${MINILIBX_DIR} -lmlx -Ilmlx -lXext -lX11 -lm

SRCS = 1_main.c 2_map_init.c 3_map_check.c 4_game_init.c 5_renderings.c 6_keypress.c 7_close_window.c
S_OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/pipex_bonus.c bonus/pipex_utils_bonus.c
B_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(S_OBJS)
	$(MAKE) $(LIBFT_DIR)
	$(MAKE) $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(CFLAGS) -g $(SRCS) $(LIBFT) $(MINILIBX) -o $(NAME)

valgrind:
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(NAME) maps/ok_0.ber

clean:
	$(MAKE) $(LIBFT_DIR) clean
	$(MAKE) $(MINILIBX_DIR) clean
	$(RM) $(S_OBJS)

fclean: clean
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
