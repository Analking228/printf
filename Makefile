PREPROC = make fclean -C ./libft
PROC = make -C ./libft
CC = clang
FLAGS = -c -Wall -Wextra -Werror
SOURCE = ft_printf.c ft_printf_utils.c micro_utils.c print_digit.c print_str_c.c \
			print_pointer.c print_unum.c print_hex.c
OBJ = $(SOURCE:%.c=%.o)
HEADER = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(PROC)
	@cp libft/libft.a ./
	@$(CC) $(FLAGS) $(SOURCE)
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@ranlib $@

$(OBJ:%.o): $(SOURCE:%.c) $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME) libft.a a.out
	@$(PREPROC)

re: fclean all

.PHONY: all clean fclean re bonus
