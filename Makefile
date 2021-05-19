NAME = push_swap.a
# PUSH_SWAP_FILES = main.o
GNL_FILES = GNL/get_next_line.o \
			GNL/get_next_line_utils.o
OBJ_FILES = $(PUSH_SWAP_FILES) $(GNL_FILES)
HEADER_FILES = push_swap_check.h
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./GNL
	rm -f *.o 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re