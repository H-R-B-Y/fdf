NAME			:= hb_math_ext.a
CFLAGS			:= -Wextra -Wall -Werror -g3 -O0

HEADERS			:= -I ./include

SRC_DIR			:= ./src
SRCS			:= $(SRC_DIR)/vector/hb_vec2.c \
				$(SRC_DIR)/vector/hb_vec22.c \
				$(SRC_DIR)/vector/hb_vec3.c \
				$(SRC_DIR)/vector/hb_vec32.c \
				$(SRC_DIR)/matrix/hb_matrix2.c \
				$(SRC_DIR)/matrix/hb_matrix22.c \
				$(SRC_DIR)/matrix/hb_matrix3.c \
				$(SRC_DIR)/matrix/hb_matrix32.c \
				$(SRC_DIR)/misc/lerp.c \
				$(SRC_DIR)/misc/maprange.c 

OBJS			:= ${SRCS:.c=.o}

MAIN			:= $(SRC_DIR)/main.c

all: $(NAME)

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		rm -rf $(OBJS)

fclean: clean

		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
