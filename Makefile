NAME		= push_swap

HEADER		= push_swap.h

SRCS		= push_swap.c ps_operation_1.c ps_operation_2.c ps_operation_3.c ft_sort.c utils_1.c utils_2.c

LIBFT		= libft/*.c

OBJS		= $(SRCS:.c=.o)

GCC			= gcc -Wall -Wextra -Werror

RM			= rm -f

all:			$(NAME)

.c.o:		=
				$(GCC) -c $< -o $(<:.c=.o)

$(NAME):		$(SRCS) $(HEADER) $(LIBFT)
						make -C libft
						$(GCC) -o $(NAME) $(SRCS) libft/libft.a

clean:
						$(RM) $(OBJS)
						make clean -C "libft"
fclean:			clean
						make fclean -C "libft"

re:						fclean all

.PHONY:			all clean fclean re
