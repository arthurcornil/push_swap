CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

SRCS_DIR=./srcs/push_swap/

BONUS_DIR=./srcs/checker_bonus/
GNL_DIR=./srcs/checker_bonus/get_next_line_bonus/

SRCS=$(SRCS_DIR)main.c\
	 $(SRCS_DIR)operations.c\
	 $(SRCS_DIR)operations2.c\
	 $(SRCS_DIR)push_swap.c\
	 $(SRCS_DIR)parser.c\
	 $(SRCS_DIR)push_swap_utils.c

BONUS_SRCS=$(BONUS_DIR)checker_bonus.c\
		   $(GNL_DIR)get_next_line_bonus.c\
		   $(GNL_DIR)get_next_line_utils_bonus.c\
		   $(SRCS_DIR)operations.c\
		   $(SRCS_DIR)operations2.c\
		   $(SRCS_DIR)parser.c\
		   $(SRCS_DIR)push_swap_utils.c


INC_DIR=./includes/

NAME=push_swap

all:
	$(CC) $(CFLAGS) $(SRCS) -I $(INC_DIR) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SRCS) -I $(INC_DIR) -o $(NAME)

bonus: $(NAME)
	$(CC) $(CFLAGS) $(BONUS_SRCS) -I $(INC_DIR) -o checker 

$(NAME): all

fclean:
	$(RM) $(NAME)
