NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
LIBFT		= libft

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLXFLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME), Darwin)
	MLXFLAGS	= -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit -Imlx
endif

INCLUDES	= ./includes
SRC_PATH	= ./src
OBJ_PATH	= ./obj

SRCS	= $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJS	= $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRCS)))))

all:	$(NAME) 

bonus:	all

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT)
			$(CC) $(CFLAGS) $^ $(MLXFLAGS) -I$(INCLUDES) -L$(LIBFT) -lft -o $@

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c* | $(OBJ_PATH)
					$(CC) $(CFLAGS) $(MLXFLAGS) -c -I$(INCLUDES) $< -o $@

$(OBJ_PATH):
				mkdir -p $(OBJ_PATH)

clean:
			$(MAKE) -C $(LIBFT) $@
			rm -rf $(OBJ_PATH)

fclean:		clean
			$(MAKE) -C $(LIBFT) $@
			rm -f $(NAME) $(CHECKER)

re:			fclean all

.PHONY:		all clean fclean re bonus