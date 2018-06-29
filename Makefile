
NAME_ASM	= asm

FLAGES          = -Wall -Wextra -Werror -c

DIR_ASM		= asmsrc
SRC_ASM		= exeasm.c
SRCS_ASM	= $(addprefix $(DIR_ASM)/, $(SRC_ASM))

DIR_ERROR	= error
SRC_ERROR	= ft_error_param.c
SRCS_ERROR	= $(addprefix $(DIR_ERROR)/, $(SRC_ERROR))

DIR_PARSING	= parsing
SRC_PARSING	= ft_is_good_format_urlfile.c ft_is_good_format_param.c\
ft_is_option.c  ft_set_options.c

SRCS_PARSING	= $(addprefix $(DIR_PARSING)/, $(SRC_PARSING))

#DIR_		=
#SRC_		=
#SRCS_		= $(addprefix $(DIR_)/, $(SRC_))

INC_DIR         = inc/

OBJS_DIR        = bin/

LIBFT_DIR               = libft

LIBFT                   = libft.a

SRCS                    = $(SRCS_ASM) $(SRCS_PARSING) $(SRCS_ERROR)

RED                             = \033[31m
GREEN                   = \033[32m
YELLO                   = \033[33m
WHITE                   = \033[37m
BIP                             = \a


OBJS                    = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all                             : $(NAME_ASM)


$(NAME_ASM)		: $(LIBFT) $(OBJS_DIR) $(OBJS) 
	@gcc $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME_ASM)
	@echo "$(GREEN)$(NAME_ASM) has been successfully created !$(WHITE)."
	@#say "$(NAME_ASM) has been successfully created !"


$(OBJS_DIR)%.o  : ./src/%.c
	@echo "$< $(GREEN) compiled $(WHITE)"
	@echo "\033[1A \033[2K \033[A"
	@gcc $(FLAGES) $< -o $@

$(LIBFT)                :
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)             :
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING);


clean                   :
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the checker binary files$(WHITE)."
	@#say "cleaned the $(NAME_ASM) binary files."

fclean                 :
	@make -C $(LIBFT_DIR) fclean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(NAME_ASM) file$(WHITE)."
	@rm -f $(NAME_ASM)
	@echo "$(GREEN)the $(NAME_ASM) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(NAME) directory is totaly cleaned !"

re                              : fclean all

norm                    :
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re
