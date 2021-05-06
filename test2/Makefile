SRCS_C	=	checker.c \
			init_all.c \
			parse_args.c \
			ft_validate.c \
			write_to_list.c \
			new_elem.c \
			ft_swap.c \
			ft_push.c \
			ft_rotate.c \
			ft_rotate_reverse.c \
			do_commands.c \
			read_command.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			check_issorted_list.c \
			free_stack.c

SRCS_PS =	push_swap.c \
			init_all.c \
			parse_args.c \
			ft_validate.c \
			write_to_list.c \
			new_elem.c \
			ft_swap.c \
			ft_push.c \
			ft_rotate.c \
			ft_rotate_reverse.c \
			sort_three.c \
			sort_five.c \
			sort_global.c \
			find_max_min.c \
			check_issorted.c \
			get_commands.c \
			ft_min_commands.c \
			free_stack.c

SRCS_B	=	visual.c \
			init_all.c \
			parse_args.c \
			ft_validate.c \
			write_to_list.c \
			new_elem.c \
			check_issorted.c \
			do_commands.c \
			ft_swap.c \
			ft_push.c \
			ft_rotate.c \
			ft_rotate_reverse.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			ft_draw.c \
			create_elem.c \
			find_max_min.c \
			index_stack.c

OBJS_C	= 	$(SRCS_C:.c=.o)

OBJS_PS =	$(SRCS_PS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

INCL	=	push_swap.h \
			libft/libft.h \
			gnl/get_next_line.h

INCL_B	=	visual.h \
			mlx.h

LIBFT	=	libft/libft.a

NAME_C	=	checker

NAME_PS =	push_swap

NAME_B	=	visual

GCC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

all:		$(NAME_C) $(NAME_PS)

bonus:		$(NAME_B)

%.o:		%.c		
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME_C):	$(OBJS_C) $(LIBFT) $(INCL) libft/*.c
			$(GCC) $(OBJS_C) $(LIBFT) -o $(NAME_C)

$(NAME_PS): $(OBJS_PS) $(LIBFT) $(INCL) libft/*.c
			$(GCC) $(OBJS_PS) $(LIBFT) -o $(NAME_PS)

$(NAME_B):	$(OBJS_B) $(LIBFT) $(INCL_B) libft/*.c
			$(GCC) -lmlx libmlx.dylib -framework OpenGL -framework AppKit $(OBJS_B) $(LIBFT) -o $(NAME_B)

$(LIBFT):	
			make -C "libft"

clean:		
			$(RM) $(OBJS_C) $(OBJS_PS) $(OBJS_B)
			make clean -C "libft"

fclean:		clean
			$(RM) $(NAME_C) $(NAME_PS) $(NAME_B)
			make fclean -C "libft"

re:			fclean all

.PHONY:		all clean fclean re