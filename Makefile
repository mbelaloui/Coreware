
NAME_ASM			= asm

FLAGES				= -Wall -Wextra -Werror -c

DIR_ASM				= asmsrc
SRC_ASM				= exeasm.c
SRCS_ASM			= $(addprefix $(DIR_ASM)/, $(SRC_ASM))

DIR_ERROR			= error
SRC_ERROR			= ft_error_param.c
SRCS_ERROR			= $(addprefix $(DIR_ERROR)/, $(SRC_ERROR))

DIR_OP				= op
SRC_OP				= ft_dell_op.c ft_get_nbr_param.c ft_get_type_param.c\
					  ft_is_type_ok.c ft_put_op.c ft_put_typ_param.c\
					  ft_set_size_label.c ft_get_cycle.c ft_get_op.c\
					  ft_init_op_tab.c ft_new_op.c ft_put_op_param.c\
					  ft_set_desc_param.c ft_get_name.c ft_get_op_tab.c\
					  ft_is_name_op.c ft_put_desc_param.c ft_put_size_label.c\
					  ft_set_param.c
SRCS_OP				= $(addprefix $(DIR_OP)/, $(SRC_OP))

DIR_PARSING			= parsing
SRC_PARSING			= ft_is_good_format_urlfile.c ft_is_good_format_param.c\
					  ft_is_option.c ft_set_options.c ft_get_basic_comment.c\
					  ft_get_end_ml_comment.c ft_get_start_ml_comment.c\
					  ft_get_start_advanced_comment.c\
					  ft_get_start_basic_comment.c ft_split_sources.c\
					  ft_split_adv_sources.c ft_split_adv_end_lm_sources.c\
					  ft_manage_advenced_comment.c
SRCS_PARSING		= $(addprefix $(DIR_PARSING)/, $(SRC_PARSING))

#DIR_		=
#SRC_		=
#SRCS_		= $(addprefix $(DIR_)/, $(SRC_))

INC_DIR				= inc/

OBJS_DIR			= bin/

LIBFT_DIR			= libft

LIBFT				= libft.a

SRCS				= $(SRCS_ASM) $(SRCS_PARSING) $(SRCS_ERROR) $(SRCS_OP)

RED					= \033[31m
GREEN				= \033[32m
YELLO				= \033[33m
WHITE				= \033[37m
BIP					= \a

OBJS				= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all					: $(NAME_ASM)


$(NAME_ASM)			: $(LIBFT) $(OBJS_DIR) $(OBJS)
	@#gcc $(OBJS) -L $(LIBFT_DIR) -lft -fsanitize=address -o $(NAME_ASM)
	@gcc $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME_ASM)
	@echo "$(GREEN)$(NAME_ASM) has been successfully created !$(WHITE)."
	# -fsanitize=address
	@#say "$(NAME_ASM) has been successfully created !"


$(OBJS_DIR)%.o		: ./src/%.c
	@echo "$< $(GREEN) compiled $(WHITE)"
	@echo "\033[1A \033[2K \033[A"
	@gcc $(FLAGES) $< -o $@

$(LIBFT)			:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR)			:
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING);
	@mkdir -p $(OBJS_DIR)$(DIR_OP);


clean				:
	@clear
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the checker binary files$(WHITE)."
	@#say "cleaned the $(NAME_ASM) binary files."

fclean				:
	@clear
	@make -C $(LIBFT_DIR) fclean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(NAME_ASM) file$(WHITE)."
	@rm -f $(NAME_ASM)
	@echo "$(GREEN)the $(NAME_ASM) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(NAME) directory is totaly cleaned !"

re					: fclean all

norm				:
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re
