CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LDFLAGS = -Lminilibx-linux -L/usr/lib -Llibft/
LDLIBS = -lmlx_Linux -lXext -lX11 -lm -lz -lft
INCS = -I./includes/ -I./libft/ -I/usr/include -Iminilibx_linux

SRCDIR = srcs/
SRCS_FIL = \
			altitude.c \
			bresenham.c \
			color.c \
			draw.c \
			error.c \
			free.c \
			init_data.c \
			init_map.c \
			isometric.c \
			key_handling.c \
			main.c \
			mlx_main.c \
			parse_map.c \
			parse_utils.c \
			rotation.c \
			transformation.c \
			translation.c \
			zoom.c \

SRCS = $(addprefix $(SRCDIR), $(SRCS_FIL))

OBJDIR = objs/
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))


# library
LIBFTDIR = libft/
LIBFT.A = $(LIBFTDIR)libft.a


NAME = $(FDF)
FDF = fdf

all:  $(OBJDIR) $(FDF)

bonus: $(OBJDIR)

$(OBJDIR):
		mkdir -p $(OBJDIR)

$(FDF): $(OBJS)
		make -sC $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(FDF) $(LDFLAGS) $(LDLIBS)

$(OBJDIR)%.o: $(SRCDIR)%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

RM = rm -f

clean:
		# $(RM) $(OBJS)
		rm -rf $(OBJDIR)
		make clean -C ${LIBFTDIR}

fclean: clean
		$(RM) $(FDF)
		make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re bonus
