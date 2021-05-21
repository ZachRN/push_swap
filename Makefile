NAME = push_swap.a
# PUSH_SWAP_FILES = main.o
GNL_FILES = srcs/GNL/get_next_line.o
OBJ_FILES = $(GNL_FILES)
HEADER_FILES = push_swap_check.h
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES) libft.a
	ar rc $@ $(OBJ_FILES) ./srcs/libft/libft.a

%.o: %.c
	$(CC) -I includes -c $(CFLAGS) -o $@ $<

%.a: 
	$(MAKE) -C ./srcs/libft

clean:
	$(MAKE) clean -C ./srcs/GNL
	$(MAKE) clean -C ./srcs/libft
	rm -f *.o 

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re