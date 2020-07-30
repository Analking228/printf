PREPROC = make fclean -C ./libft
PROC = make -C ./libft
CC = gcc
FLAGS = -c #-Wall -Wextra -Werror 
SOURCE = ft_printf.c ft_printf_utils.c body.c
OBJ = $(SOURCE:%.c=%.o)
HEADER = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(PROC)
	cp libft/libft.a ./
	$(CC) $(FLAGS) $(SOURCE)
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	ranlib $@

$(OBJ:%.o): $(SOURCE:%.c) $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) libft.a a.out
	$(PREPROC)

re: fclean all

.PHONY: all clean fclean re bonus
