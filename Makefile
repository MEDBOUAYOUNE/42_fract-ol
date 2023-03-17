.SILENT:
NAME = fractol

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRC = main.c \
		Mandelbrot.c \
			Julia.c \
				mlx_hooks.c \
					coloring.c \
						utils_err.c \
							utils.c \
								libft.c 

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)
clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all