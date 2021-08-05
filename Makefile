NAME = push_swap
OBJ_FILES = actioninputcheck.o\
				actionlinkedlist.o\
				actions_prr.o\
				actions_sr.o\
				errorhandle.o\
				numinputcheck.o\
				sort_list.o\
				stacklinkedlist.o\
				main.o
HEADER_FILES = push_swap_check.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assembling Program completely
	$(CC) -o $@ $^ srcs/libft/libft.a $(CFLAGS)
	@echo Program assembled!

%.o: %.c
	$(CC) -I ./includes -c $(CFLAGS) -o $@ $<

build_dir:
	clear
	@if [ -d "./$(BUILD_DIR)" ]; then \
	echo "Build Directory Already Exists"; \
	else \
	mkdir -p $(BUILD_DIR); \
	fi

clean:
	clear
	@echo Cleaning all object files
	@ make clean -C ./srcs/libft > /dev/null
	@echo libft.o files cleaned
	@ rm -f *.o

fclean: clean
	@ echo Cleaning all Object Files
	@ make fclean -C ./srcs/libft > /dev/null
	@echo Cleaning Libraries
	@echo Removing Program
	@echo Removing Build Directory
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re