CC=cc

CFLAGS=-Wall -Wextra -Werror -g

RM=rm -rf

SRCS_DIR=./srcs/push_swap/

BONUS_DIR=./srcs/checker_bonus/
GNL_DIR=./srcs/checker_bonus/get_next_line_bonus/
LIBFTPRINTF_DIR=./libftprintf/
LIBFTPRINTF=$(LIBFTPRINTF_DIR)libftprintf.a

SRCS=$(SRCS_DIR)main.c\
	 $(SRCS_DIR)operations.c\
	 $(SRCS_DIR)operations2.c\
	 $(SRCS_DIR)push_swap.c\
	 $(SRCS_DIR)parser.c\
	 $(SRCS_DIR)push_swap_utils.c \
	 $(SRCS_DIR)turk_sort.c \
	 $(SRCS_DIR)turk_sort_utils.c \
	 $(SRCS_DIR)turk_sort_utils2.c \
	 $(SRCS_DIR)find_index.c \
	 $(SRCS_DIR)handle_errors.c


BONUS_SRCS=$(BONUS_DIR)checker_bonus.c\
		   $(GNL_DIR)get_next_line_bonus.c\
		   $(GNL_DIR)get_next_line_utils_bonus.c\
		   $(SRCS_DIR)operations.c\
		   $(SRCS_DIR)operations2.c\
		   $(SRCS_DIR)parser.c\
		   $(SRCS_DIR)push_swap_utils.c

OBJS=$(SRCS:.c=.o)
BOBJS=$(BONUS_SRCS:.c=.o)

INC_DIR=./includes/

NAME=push_swap

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFTPRINTF_DIR)includes/ -c $< -o $@

all: libftprintf.a $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o push_swap 

bonus: $(NAME)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFTPRINTF) -o $(NAME)

libftprintf.a:
	@make -C $(LIBFTPRINTF_DIR)

$(NAME): all

clean:
	$(RM) $(SRCS_DIR)$(OBJS)
	@make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all
