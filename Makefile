NAME			:= fdf.out
# CFLAGS			:= -Wextra -Wall -Werror -g3 -O0 -fsanitize=address
CFLAGS			:= -g3 -O0 -fsanitize=address

HEADERS			:= -I ./include

LIB_DIR			:= ./lib

HB_MATH_DIR		:= $(abspath $(LIB_DIR)/hb_math_ext)
HB_MATH			:= $(HB_MATH_DIR)/hb_math_ext.a

LIBFT_DIR		:= $(abspath $(LIB_DIR)/libft)
LIBFT			:= $(LIBFT_DIR)/libft.a

LIBMLX_DIR		:= $(abspath $(LIB_DIR)/MLX42)
LIBMLX			:= $(LIBMLX_DIR)/build/libmlx42.a
LIBFLAGS		:=  -ldl `pkg-config --libs glfw3` -pthread -lm

SRC_DIR			:= ./src
SRCS			:= $(SRC_DIR)/parse/parse_validate.c \
				$(SRC_DIR)/parse/parse_data.c \
				$(SRC_DIR)/parse/parse_file.c \
				$(SRC_DIR)/parse/parse_util.c \
				$(SRC_DIR)/parse/parse.c \
				$(SRC_DIR)/project/execute_pipeline.c \
				$(SRC_DIR)/project/isometric.c \
				$(SRC_DIR)/project/projection_defaults.c \
				$(SRC_DIR)/project/projections.c \
				$(SRC_DIR)/utility.c

OBJS			:= ${SRCS:.c=.o}

MAIN			:= $(SRC_DIR)/main.c

all: $(NAME)

$(LIBFT):
		$(MAKE) --directory $(LIBFT_DIR) all CFLAGS="$(CFLAGS)"

$(LIBMLX):
		cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make CFLAGS="$(CFLAGS)" -C $(LIBMLX_DIR)/build -j4

$(HB_MATH):
		$(MAKE) --directory $(HB_MATH_DIR) all CFLAGS="$(CFLAGS)"

.c.o:
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)


$(NAME): $(MAIN) $(OBJS) $(LIBFT) $(LIBMLX) $(HB_MATH)
		$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(HB_MATH) $(LIBFT) $(LIBMLX) $(LIBFLAGS) -o $(NAME)

clean:
		$(MAKE) --directory $(LIBFT_DIR) clean
		$(MAKE) --directory $(HB_MATH_DIR) clean
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(LIBMLX_DIR)/build
		$(MAKE) --directory $(LIBFT_DIR) fclean
		$(MAKE) --directory $(HB_MATH_DIR) fclean
		rm -rf $(NAME)

rm:
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, test
