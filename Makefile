# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 23:57:40 by ualkan            #+#    #+#              #
#    Updated: 2025/03/21 10:57:38 by ualkan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

define HEADER
	echo "╔═══════════════════════════════════════════════╗"
	echo "║         🌀 FRACTOL PROJECT BUILD 🌀           ║"
	echo "║         By ualkan ~ 42 Istanbul Edition       ║"
	echo "║     『構築中... Loading Your Destiny』        ║"
	echo "╚═══════════════════════════════════════════════╝"
endef

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = src
BONUS_DIR = bonus

SRC = $(addprefix $(SRC_DIR)/, main.c init.c render.c utils.c handler.c maker.c color.c)
BONUS_SRC = $(addprefix $(BONUS_DIR)/, color_bonus.c handler_bonus.c init_bonus.c main_bonus.c maker_bonus.c maker2_bonus.c render_bonus.c utils_bonus.c)

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	@echo "🔨 Building $(NAME)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I$(MLX_DIR) $(MLX_FLAGS)

bonus: $(BONUS_OBJ) $(MLX)
	@echo "🔨 Building bonus version"
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME) -I$(MLX_DIR) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	@echo "🔨 Building MiniLibx"
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
