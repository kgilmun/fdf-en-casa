# Configuración
NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g \
	-I$(LIB_DIR) \
	-I$(GNL_DIR) \
	-I$(MLX_DIR)

# Directorios
LIB_DIR = ../libft
GNL_DIR = ../2get_next_line
MLX_DIR = minilibx-linux

LIBFT = $(LIB_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Archivos fuente (orden manual, sin wildcard)
SRCS = main.c open_window.c read_map.c store_points.c draw_map.c controls.c put_color.c map_utils.c \
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \
	map_validation.c render_utils.c

# Objetos (coinciden con los nombres de SRCS sin rutas)
OBJS = main.o open_window.o read_map.o store_points.o draw_map.o controls.o put_color.o map_utils.o \
	get_next_line.o get_next_line_utils.o map_validation.o render_utils.o

# Regla principal
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -L$(LIB_DIR) -lft -lXext -lX11 -lm

# Regla genérica para compilar los .c locales
%.o: %.c fdf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas explícitas para los .c que están en subcarpeta
get_next_line.o: $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -c $(GNL_DIR)/get_next_line.c -o get_next_line.o

get_next_line_utils.o: $(GNL_DIR)/get_next_line_utils.c $(GNL_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -c $(GNL_DIR)/get_next_line_utils.c -o get_next_line_utils.o

# Librerías
$(LIBFT):
	make -C $(LIB_DIR)

$(MLX):
	make -C $(MLX_DIR)

# Limpieza
clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

