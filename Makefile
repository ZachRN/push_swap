NAME = push_swap
#PUSH_SWAP_OBJ_FILES = 
CHECKER_NAME = checker
CHECKER_OBJ_FILES =	$(BUILD_DIR)/actioninputcheck.o\
					$(BUILD_DIR)/actionlinkedlist.o\
					$(BUILD_DIR)/actions_prr.o\
					$(BUILD_DIR)/actions_sr.o\
					$(BUILD_DIR)/errorhandle.o\
					$(BUILD_DIR)/numinputcheck.o\
					$(BUILD_DIR)/sort_list.o\
					$(BUILD_DIR)/stacklinkedlist.o\
					$(BUILD_DIR)/strnuminputcheck.o\
					$(BUILD_DIR)/main.o
BUILD_DIR = build
SRC_DIR = srcs/checker
HEADER_FILES = includes/push_swap_check.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: build_dir $(NAME)

$(NAME): $(OBJ_FILES)
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assembling Program completely
	@$(CC) -o $@ $^ srcs/libft/libft.a $(CFLAGS)
	@echo push_swap has been made!

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -I ./includes/ -c $(CFLAGS) -o $@ $<

bonus: build_dir checker

checker: $(CHECKER_OBJ_FILES)
	clear
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assemling checker
	@$(CC) -o $(CHECKER_NAME) $^	 srcs/libft/libft.a $(CFLAGS)
	@echo checker has been assembled!

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
	@ rm -f $(BUILD_DIR)/*.o

fclean: clean
	@ echo Cleaning all Object Files
	@ make fclean -C ./srcs/libft > /dev/null
	@echo Removing Build Directory
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi
	@ rm -f $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re