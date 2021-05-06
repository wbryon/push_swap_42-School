SRCS_PS		= push_swap.c \
			  rotate.c \
			  rev_rotate.c \
			  swap.c \
			  push.c \
			  sort_five.c \
			  global_sort.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \
			  utils_1.c \
			  utils_2.c \
			  min_commands.c \
			  get_commands.c \
			  read_commands.c

SRCS_CH		= checker.c \
			  rotate.c \
			  rev_rotate.c \
			  swap.c \
			  push.c \
			  sort_five.c \
			  global_sort.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \
			  utils_1.c \
			  utils_2.c \
			  min_commands.c \
			  get_commands.c \
			  read_commands.c 

SRCS_VS		= visualizer.c \
			  rotate.c \
			  rev_rotate.c \
			  swap.c \
			  push.c \
			  sort_five.c \
			  global_sort.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \
			  utils_1.c \
			  utils_2.c \
			  min_commands.c \
			  get_commands.c \
			  read_commands.c \
			  draw.c \
			  ascend_index.c

OBJS_PS		= $(SRCS_PS:.c=.o)

OBJS_CH		= $(SRCS_CH:.c=.o)

OBJS_VS		= $(SRCS_VS:.c=.o)

INCL		= push_swap.h \
			  libft/libft.h \
			  gnl/get_next_line.h

INCL_VS		= visualizer.h

LIBFT		= libft/libft.a

NAME_PS		= push_swap

NAME_CH		= checker

NAME_VS		= visualizer

GCC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		  $(NAME_CH) $(NAME_PS)

bonus:		  $(NAME_VS)

%.o:		  %.c		
			  $(GCC) $(CFLAGS) -c $< -o $@

$(NAME_CH):	  $(OBJS_CH) $(LIBFT) $(INCL) libft/*.c
			  $(GCC) $(OBJS_CH) $(LIBFT) -o $(NAME_CH)

$(NAME_PS):   $(OBJS_PS) $(LIBFT) $(INCL) libft/*.c
			  $(GCC) $(OBJS_PS) $(LIBFT) -o $(NAME_PS)

$(NAME_VS):   $(OBJS_VS) $(LIBFT) $(INCL_VS) libft/*.c
			  $(GCC) -lmlx libmlx.dylib -framework OpenGL -framework AppKit $(OBJS_VS) $(LIBFT) -o $(NAME_VS)

$(LIBFT):	
			  make -C "libft"

clean:		
			  $(RM) $(OBJS_CH) $(OBJS_PS) $(OBJS_VS)
			  make clean -C "libft"

fclean:		  clean
			  $(RM) $(NAME_CH) $(NAME_PS) $(NAME_VS)
			  make fclean -C "libft"

re:			  fclean all

.PHONY:		  all clean fclean re