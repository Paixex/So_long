NAME    = so_long

INC     = -I include

LIBFTDIR	= inc/Libft
LIBFT   	= $(LIBFTDIR)/libft.a
LIBMLXDIR 	= inc/minilibx-linux
LIBMLX  	= $(LIBMLXDIR)/libmlx_Linux.a
LFLAGS		= -L /bin/valgrind

CFLAGS  = -Wall -Werror -Wextra -O3 -g -fsanitize=address
UNAME   := $(shell uname)

LFLAGS  	= -L$(LIBMLXDIR) -lmlx -L${LIBFTDIR} -lft $(LDFLAGS) -fsanitize=address# if you decided to install libmlx.a locally you don't need "-L$(LIBMLX) -lmlx" the school also has it locally as well...

SRC     = 	src/destroy.c					\
			src/errors.c					\
			src/get_map.c					\
			src/get_next_line.c				\
			src/check_map.c					\
			src/check_path.c				\
			src/so_long.c					\
			src/free_trim.c					\
			src/hook_run.c					\
			src/mlx_start.c					\
			src/player.c					\
			src/map_render.c

OBJ     = $(SRC:%.c=%.o)

ifeq ($(UNAME), Darwin)
	CC = cc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	CC = clang
else
	CC = cc
	LFLAGS += -lbsd -lXext -lX11 -lm
endif


all: $(NAME)

$(NAME): runlibft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

runlibft:
	make -C $(LIBFTDIR) --no-print-directory

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"
