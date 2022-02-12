NAME = push_swap
PUSH_SWAP_OBJ_FILES =	$(BUILD_DIR)/ps_actions_prr.o\
						$(BUILD_DIR)/ps_actions_sr.o\
						$(BUILD_DIR)/ps_errorhandle.o\
						$(BUILD_DIR)/ps_main.o\
						$(BUILD_DIR)/ps_numinputcheck.o\
						$(BUILD_DIR)/ps_radix_sort.o\
						$(BUILD_DIR)/ps_short_sort.o\
						$(BUILD_DIR)/ps_sort_value_radix.o\
						$(BUILD_DIR)/ps_stacklinkedlist.o\
						$(BUILD_DIR)/ps_strnuminputcheck.o
CHECKER_NAME = checker
CHECKER_OBJ_FILES =	$(BUILD_DIR)/ch_actioninputcheck.o\
					$(BUILD_DIR)/ch_actionlinkedlist.o\
					$(BUILD_DIR)/ch_actions_prr.o\
					$(BUILD_DIR)/ch_actions_sr.o\
					$(BUILD_DIR)/ch_errorhandle.o\
					$(BUILD_DIR)/ch_numinputcheck.o\
					$(BUILD_DIR)/ch_sort_list.o\
					$(BUILD_DIR)/ch_stacklinkedlist.o\
					$(BUILD_DIR)/ch_strnuminputcheck.o\
					$(BUILD_DIR)/ch_main.o
BUILD_DIR = build
VPATH = srcs/checker:srcs/push_swap_src
HEADER_FILES = includes/push_swap_check.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: build_dir $(NAME)

$(NAME): $(PUSH_SWAP_OBJ_FILES)
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assembling Program completely
	@$(CC) -o $@ $^ srcs/libft/libft.a $(CFLAGS)
	@echo push_swap has been made!

$(BUILD_DIR)/%.o: %.c
	@$(CC) -I ./includes/ -c $(CFLAGS) -o $@ $<

bonus: build_dir checker

checker: $(CHECKER_OBJ_FILES)
	clear
	@echo Compiling Libft, GNL, and ft_printf together
	@ make -C ./srcs/libft/ bonus > /dev/null
	@echo libft.a compiled
	@echo Assemling checker
	@$(CC) -o $(CHECKER_NAME) $^ srcs/libft/libft.a $(CFLAGS)
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
	@echo Removing Build Directory
	@if [ -d "./$(BUILD_DIR)" ]; then \
	rmdir $(BUILD_DIR); fi
	
fclean: clean
	@ make fclean -C ./srcs/libft > /dev/null
	@ rm -f $(CHECKER_NAME)
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re