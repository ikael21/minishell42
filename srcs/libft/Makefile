NAME = libft.a

OBJS_DIR = objs_and_dfiles

#colors for beauty
GREEN =		\033[32;1m
RESET =		\033[0m
BLUE =		\033[34;1m
RED = 		\033[31;1m

FUNCS =		ft_bzero.c		ft_isalnum.c	ft_toupper.c\
			ft_isalpha.c	ft_isdigit.c	ft_isprint.c\
			ft_memccpy.c	ft_memchr.c		ft_memcmp.c\
			ft_memcpy.c		ft_memmove.c	ft_memset.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_strnstr.c	ft_strncmp.c	ft_strlen.c\
			ft_tolower.c	ft_atoi.c		ft_calloc.c\
			ft_strdup.c		ft_isascii.c	ft_strchr.c\
			ft_strrchr.c	ft_strlcpy.c	ft_strlcat.c\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c\
			ft_itoa.c		ft_putnbr_fd.c	ft_split.c\
			ft_strmapi.c	ft_lstnew.c		ft_lstadd_front.c\
			ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
			ft_lstmap.c		ft_strcmp.c

O_OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o, $(FUNCS))
D_FILES = $(patsubst %.c,$(OBJS_DIR)/%.d, $(FUNCS))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(O_OBJS)
	@ar rcs $(NAME) $(O_OBJS)
	@echo "$(BLUE)LIBFT$(RESET) $(GREEN)COMPILED!$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c
	@gcc $(FLAGS) -I../../includes -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)LIBFT$(RESET) $(RED)DELETED$(RESET)"

re: fclean all

.PHONY: all clean fclean re create_dir
