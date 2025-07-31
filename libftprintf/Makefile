CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

LIBFT_DIR=./libft/

SRCS_DIR=./srcs/

LIBFT_DIR=./libft/

SRCS=$(SRCS_DIR)ft_fts.c\
	 $(SRCS_DIR)ft_get_format.c\
	 $(SRCS_DIR)ft_print_char.c\
	 $(SRCS_DIR)ft_print_uint.c\
	 $(SRCS_DIR)ft_print_ptr.c\
	 $(SRCS_DIR)ft_print_hex.c\
	 $(SRCS_DIR)ft_print_int.c\
	 $(SRCS_DIR)ft_print_str.c\
	 $(SRCS_DIR)ft_printf.c

BSRCS=$(SRCS_DIR)ft_fts_bonus.c\
	  $(SRCS_DIR)ft_get_format_bonus.c\
	  $(SRCS_DIR)ft_indent_bonus.c\
	  $(SRCS_DIR)ft_print_char_bonus.c\
	  $(SRCS_DIR)ft_print_hex_bonus.c\
	  $(SRCS_DIR)ft_print_int_bonus.c\
	  $(SRCS_DIR)ft_print_percent_bonus.c\
	  $(SRCS_DIR)ft_print_ptr_bonus.c\
	  $(SRCS_DIR)ft_print_str_bonus.c\
	  $(SRCS_DIR)ft_init_tab_bonus.c\
	  $(SRCS_DIR)ft_print_uint_bonus.c\
	  $(SRCS_DIR)ft_printf_bonus.c\

OBJS=${SRCS:.c=.o}
BOBJS=${BSRCS:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./libftprintf.a
	ar rc $(NAME) $?

clean: 
	$(RM) $(OBJS) $(BOBJS)
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BOBJS) 
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a ./libftprintf.a
	ar rc $(NAME) $?

.PHONY: fclean clean re
