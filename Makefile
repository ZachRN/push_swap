NAME = push_swap.a
BUILD_DIR = build
# PUSH_SWAP_FILES = main.o
GNL_SRC_PATH = srcs/GNL/
GNL_SRCS = $(wildcard $(GNL_SRC_PATH)*.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)
GNL_OBJS = $(GNL_OBJS:$(GNL_SRC_PATH)%:%)
OBJ_FILES = $(patsubst %,$(BUILD_DIR)/%.o,$(GNL_OBJS))
HEADER_FILES = $(wildcard includes/*.h)
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

$(BUILD_DIR)/%.o: $(GNL_SRC_PATH)%.c
	$(CC) -c $(CFLAGS) -o $@ $<

#dir:
#	mkdir -p build
# %.a: 

# 	$(MAKE) -C ./srcs/libft

clean:
	$(MAKE) clean -C ./srcs/GNL
	rm -f *.o 
	#rmdir $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re