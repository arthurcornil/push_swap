CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

SRCS_DIR=./srcs/

SRCS=	$(SRCS_DIR)main.c\
		$(SRCS_DIR)operations.c\
		$(SRCS_DIR)operations2.c\
		$(SRCS_DIR)push_swap.c\
		$(SRCS_DIR)parser.c

INC=./includes/

NAME=push_swap

all:
	$(CC) $(CFLAGS) $(SRCS) -I $(INC) -o $(NAME)

$(NAME): all
