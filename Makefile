NAME = push_swap.a
BUILD_DIR = build
# PUSH_SWAP_FILES = main.o
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJ_FILES) build_dir
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs bonus > /dev/null
	@echo libft.a compiled
	@echo Compiling Push_swap files together
#code in
	@echo Push_swap.a completed
	@echo Assembling Program completely
#code in
	@echo Program assembled!

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
	@ make clean -C ./srcs > /dev/null
	@echo libft.o files cleaned

fclean: clean
	@ echo Cleaning all Object Files
	@ make fclean -C ./srcs > /dev/null
	@echo Cleaning Libraries
	@echo Removing Program
	@echo Removing Build Directory
	@ rmdir $(BUILD_DIR)
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re