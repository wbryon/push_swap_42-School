NAME_PS		= push_swap

HEADER		= push_swap.h

SRCS		= push_swap.c \
			  rotate.c \
			  rev_rotate.c \
			  ps_operation_1.c \
			  ps_operation_2.c \
			  ps_operation_3.c \
			  ft_sort.c \
			  utils_1.c \
			  utils_2.c \
			  init_vars.c

LIBFT		= libft/*.c

OBJS		= $(SRCS:.c=.o)

GCC			= gcc -Wall -Wextra -Werror

RM			= rm -f

all:			$(NAME_PS)

.c.o:		=
				$(GCC) -c $< -o $(<:.c=.o)

$(NAME_PS):		$(SRCS) $(HEADER) $(LIBFT)
						make -C libft
						$(GCC) -o $(NAME_PS) $(SRCS) libft/libft.a

clean:
						$(RM) $(OBJS)
						make clean -C "libft"
fclean:			clean
						make fclean -C "libft"
						$(RM) $(NAME_PS)

re:						fclean all

.PHONY:			all clean fclean re
