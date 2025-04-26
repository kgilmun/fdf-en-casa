
#Configuración

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror \
	-I$(LIB_DIR) \
	-I$(GNL_DIR) \
	-I$(MLX_DIR)

#Directorios 

LIB_DIR	= ../libft
GNL_DIR	= ../2get_next_line
MLX_DIR	= minilibx-linux

LIBFT = $(LIB_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a


#HEADERS = $(LIB_DIR)/libft.h $(GNL_DIR)/get_next_line.h NO SE SI HAY QUE HACER ALGO CON ESTO

SRCS = main.c open_window.c read_map.c store_points.c\
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c


#Archivos

OBJS = $(SRCS:.c=.o)

#Reglas

all: $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -L$(LIB_DIR) -lft -lXext -lX11 -lm

clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


