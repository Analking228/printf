CC = clang
CFLAGS = -c -Wall -Wextra -Werror -I.
SOURCE = ft_isspace.c ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
			ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
			ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c \
			ft_calloc.c ft_memchr.c ft_putstr.c ft_strmapi.c \
			ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strncmp.c \
			ft_isalpha.c ft_memcpy.c ft_split.c ft_strnstr.c \
			ft_isascii.c ft_memmove.c ft_strchr.c ft_strrchr.c \
			ft_isdigit.c ft_memset.c ft_strdup.c ft_strtrim.c \
			ft_isprint.c ft_putchar.c ft_strjoin.c ft_substr.c
BSOURCE = ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c
OBJ = $(SOURCE:%.c=%.o)
BOBJ = $(BSOURCE:%.c=%.o)
HEADER = libft.h
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@

$(OBJ:%.o): $(SOURCE:%.c) $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BOBJ:%.o): $(BSOURCE:%.c) $(HEADER)
	@$(CC) $(CFLAGS) -с $< -o $@

bonus: $(BOBJ) $(OBJ)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
