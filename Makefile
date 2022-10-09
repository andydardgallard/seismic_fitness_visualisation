NAME = pia

SRC = pia.c ./gnl/get_next_line_utils.c ./gnl/get_next_line.c parcer.c ft_split.c mlx.c draw.c calc.c menu.c

OBJ = $(SRC:.c=.o)

OPENGL = libmlx.a -framework OpenGL -framework AppKit -lm

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(%.o): $(%.c)
				$(CC) -o $@

$(NAME): $(OBJ) pia.h
				@echo "\nCompiling --->"
				@$(CC) $(OPENGL) $(SRC) -o $(NAME)
				@echo "Done\n"

clean:
				@rm -rf $(OBJ)
				@echo "\nDelete objects\n"

fclean: 		clean
				@rm -rf $(NAME)
				@echo "\nRemoved all files\n"

re: 			all
				@echo  "\nRemake\n"

.PHONY:			all clean fclean re
