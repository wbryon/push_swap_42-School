SRCS_PS		= push_swap.c \
			  rotate.c \
			  ps_ops_1.c \
			  ps_ops_2.c \
			  ps_ops_3.c \
			  ft_sort_five.c \
			  ft_sort_global.c \
			  utils_1.c \
			  utils_2.c \
			  utils_3.c \
			  list.c \
			  ascend_index.c

SRCS_CH		= checker.c \
			  rotate.c \
			  ps_ops_1.c \
			  ps_ops_2.c \
			  ps_ops_3.c \
			  ft_sort_five.c \
			  ft_sort_global.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c \
			  utils_1.c \
			  utils_2.c \
			  utils_3.c \
			  list.c \
			  ascend_index.c

OBJS_PS		= $(SRCS_PS:.c=.o)

OBJS_CH		= $(SRCS_CH:.c=.o)

INCL		= push_swap.h \
			  libft/libft.h \
			  gnl/get_next_line.h

LIBFT		= libft/*.c

NAME_PS		= push_swap

NAME_CH		= checker

GCC		= 	   gcc
RM		= 	   rm -f

CFLAGS	= 	   -Wall -Wextra -Werror

all:		   $(NAME_CH) $(NAME_PS)

%.o:		   %.c		
			   $(GCC) $(CFLAGS) -c $< -o $@

$(NAME_CH):	   $(OBJS_CH) $(LIBFT) $(INCL) libft/*.c
			   $(GCC) $(OBJS_CH) $(LIBFT) -o $(NAME_CH)

$(NAME_PS):    $(OBJS_PS) $(LIBFT) $(INCL) libft/*.c
			   $(GCC) $(OBJS_PS) $(LIBFT) -o $(NAME_PS)

$(LIBFT):	
			   make -C "libft"

clean:		
			   @$(RM) $(OBJS_CH) $(OBJS_PS)
			   make clean -C "libft"
			   @echo "\033[33;31m===> Deleting the objects\033[33;37m"

fclean:		   clean
			   $(RM) $(NAME_CH) $(NAME_PS)
			   make fclean -C "libft"

re:			   fclean all

.PHONY:		   all clean fclean re