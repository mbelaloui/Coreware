# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 12:33:04 by mbelalou          #+#    #+#              #
#    Updated: 2018/09/20 18:53:31 by mbelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM			= asm
NAME_VM				= vm

FLAGES				= -Wall -Wextra -Werror -c

DIR_ASM				= asm
SRC_ASM				= asm_exe.c
EXE_ASM				= $(addprefix $(DIR_ASM)/, $(SRC_ASM))

DIR_VM				= vm
SRC_VM				= vm_exe.c
EXE_VM				= $(addprefix $(DIR_VM)/, $(SRC_VM))

DIR_PARSING_ASM		= asm/parsing
SRC_PARSING_ASM		= ft_manage_url.c ft_extract_simple_comment.c\
					  ft_extract_ml_comment.c ft_clean_file.c\
					  ft_skip_spaces.c ft_get_index_end.c ft_get_data.c\
					  ft_extraire_head_info.c ft_get_type_args.c\
					  ft_prepare_args.c ft_extract_source.c ft_is_option.c\
					  ft_set_asm_options.c ft_extract_asm_options.c\
					  ft_init_asm_option.c
SRCS_PARSING_ASM	= $(addprefix $(DIR_PARSING_ASM)/, $(SRC_PARSING_ASM))

DIR_SYMBOLE_ASM		= asm/parsing/symbole
SRC_SYMBOLE_ASM		= ft_new_symbole.c ft_is_in_symbole.c ft_add_symbole.c\
					  ft_dell_symbole.c ft_dell_list_symbole.c\
					  ft_put_list_symbole.c ft_init_symbole_tab.c
SRCS_SYMBOLE_ASM	= $(addprefix $(DIR_SYMBOLE_ASM)/, $(SRC_SYMBOLE_ASM))

DIR_LABEL_ASM		= asm/parsing/label
SRC_LABEL_ASM		= ft_set_used_label.c ft_check_for_label.c
SRCS_LABEL_ASM		= $(addprefix $(DIR_LABEL_ASM)/, $(SRC_LABEL_ASM))

DIR_ERROR_ASM		= asm/error
SRC_ERROR_ASM		= ft_error_param.c ft_error_reading_file.c ft_error_label.c\
					  ft_error_op.c ft_error_head.c ft_error_inst.c\
					  ft_error_args.c ft_error_option.c
SRCS_ERROR_ASM		= $(addprefix $(DIR_ERROR_ASM)/, $(SRC_ERROR_ASM))

DIR_PRINTING_ASM	= asm/printing
SRC_PRINTING_ASM	= ft_put_inst.c ft_put_instlist.c ft_warning.c\
					  ft_put_player.c ft_put_source_bin.c\
					  ft_put_source_decimal.c ft_put_source_hexa.c\
					  ft_put_usage.c ft_put_option.c  ft_put_help.c
SRCS_PRINTING_ASM	= $(addprefix $(DIR_PRINTING_ASM)/, $(SRC_PRINTING_ASM))

DIR_RUN_ASM			= asm/run
SRC_RUN_ASM			= ft_translate_player.c ft_extract_info_player.c\
					  ft_get_arg_translat.c 
SRCS_RUN_ASM	= $(addprefix $(DIR_RUN_ASM)/, $(SRC_RUN_ASM))

DIR_INST_ASM		= asm/inst
SRC_INST_ASM		= ft_dell_inst.c ft_dell_list_instlist.c\
					  ft_add_end_instlist.c ft_new_inst.c   \
					  ft_get_size_program.c ft_get_desc_args.c\
					  ft_get_size_bin_inst.c\
					  ft_get_size_inst.c ft_handle_args_inst.c
SRCS_INST_ASM		= $(addprefix $(DIR_INST_ASM)/, $(SRC_INST_ASM))

DIR_PLAYER_ASM		= asm/player
SRC_PLAYER_ASM		= ft_free_player.c ft_put_head.c ft_put_bynary.c\
					  ft_put_src.c ft_make_out_put.c
SRCS_PLAYER_ASM		= $(addprefix $(DIR_PLAYER_ASM)/, $(SRC_PLAYER_ASM))

DIR_OP				= op
SRC_OP				= ft_dell_op.c ft_get_nbr_param.c ft_get_type_param.c\
					  ft_is_type_ok.c ft_put_op.c ft_put_type_param.c\
					  ft_set_size_label.c ft_get_cycle.c ft_get_op.c\
					  ft_init_op_tab.c ft_new_op.c ft_put_op_param.c\
					  ft_set_desc_param.c ft_get_name.c ft_get_op_tab.c\
					  ft_is_name_op.c ft_put_desc_param.c ft_put_size_label.c\
					  ft_set_param.c ft_free_optab.c ft_is_direct.c\
					  ft_is_indirect.c ft_is_register.c  ft_is_label.c\
					  ft_is_need_desc_op.c
SRCS_OP				= $(addprefix $(DIR_OP)/, $(SRC_OP))

DIR_PARSING_VM		= vm/parsing
SRC_PARSING_VM		= ft_check_signature.c ft_get_next_oct.c ft_get_vm_magic.c\
					  ft_get_vm_name.c ft_get_vm_size.c ft_is_null.c\
					  ft_get_vm_comment.c ft_get_vm_src.c ft_init_option_vm.c
SRCS_PARSING_VM		= $(addprefix $(DIR_PARSING_VM)/, $(SRC_PARSING_VM))

DIR_ERROR_VM		= vm/error
SRC_ERROR_VM		= ft_error_reading_file.c ft_error_exe.c
SRCS_ERROR_VM		= $(addprefix $(DIR_ERROR_VM)/, $(SRC_ERROR_VM))

#DIR_		=
#SRC_		=
#SRCS_		= $(addprefix $(DIR_)/, $(SRC_))


INC_DIR				= inc/

OBJS_DIR			= bin/
OBJS_DIR_ASM		= bin_asm/
OBJS_DIR_VM			= bin_vm/

LIBFT_DIR			= libft

LIBFT				= libft.a

SRCS_ASM			= $(EXE_ASM) $(SRCS_PARSING_ASM) $(SRCS_ERROR_ASM)\
					  $(SRCS_OP) $(SRCS_PRINTING_ASM) $(SRCS_INST_ASM)\
					  $(SRCS_PLAYER_ASM) $(SRCS_SYMBOLE_ASM) $(SRCS_LABEL_ASM)\
					  $(SRCS_RUN_ASM)

SRCS_VM				= $(EXE_VM) $(SRCS_OP) \
					  $(SRCS_PARSING_VM) $(SRCS_ERROR_VM)

RED					= \033[31m
GREEN				= \033[32m
YELLO				= \033[33m
WHITE				= \033[37m
BIP					= \a

OBJS_ASM			= $(addprefix $(OBJS_DIR), $(SRCS_ASM:.c=.o))
OBJS_VM				= $(addprefix $(OBJS_DIR), $(SRCS_VM:.c=.o))

all					: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM)			: $(LIBFT) $(OBJS_DIR_ASM) $(OBJS_ASM)
	@#echo $(OBJS_ASM)
	@gcc $(OBJS_ASM) -L $(LIBFT_DIR) -lft -fsanitize=address -o $(NAME_ASM)
	@#gcc $(OBJS_ASM) -L $(LIBFT_DIR) -lft -o $(NAME_ASM)
	@echo "$(GREEN)$(NAME_ASM) has been successfully created !$(WHITE)."
	# -fsanitize=address
	@#say "$(NAME_ASM) has been successfully created !"

$(NAME_VM)			: $(LIBFT) $(OBJS_DIR_VM) $(OBJS_VM)
	@#echo $(OBJS_VM)
	@gcc $(OBJS_VM) -L $(LIBFT_DIR) -lft -o $(NAME_VM)
	@#gcc $(OBJS_VM) -L $(LIBFT_DIR) -lft -fsanitize=address -o $(NAME_VM)
	@echo "$(GREEN)$(NAME_VM) has been successfully created !$(WHITE)."
	# -fsanitize=address
	@#say "$(NAME_ASM) has been successfully created !"


$(OBJS_DIR)%.o		: ./src/%.c $(INC_DIR)
	@echo "$< $(GREEN) compiled $(WHITE)"
	@echo "\033[1A \033[2K \033[A"
	@gcc  $(FLAGES) $< -o $@

$(LIBFT)			:
	@make -C $(LIBFT_DIR)

$(OBJS_DIR_ASM)		:
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_RUN_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_PRINTING_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_SYMBOLE_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_LABEL_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_OP);
	@mkdir -p $(OBJS_DIR)$(DIR_INST_ASM);
	@mkdir -p $(OBJS_DIR)$(DIR_PLAYER_ASM);

$(OBJS_DIR_VM)			:
	@mkdir -p $(OBJS_DIR);
	@mkdir -p $(OBJS_DIR)$(DIR_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_OP);
	@mkdir -p $(OBJS_DIR)$(DIR_PRINTING);
	@#mkdir -p $(OBJS_DIR)$(DIR_INST);
	@#mkdir -p $(OBJS_DIR)$(DIR_PLAYER);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR_VM);

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
	@rm -f $(NAME_ASM) $(NAME_VM)
	@echo "$(GREEN)the $(NAME_ASM) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(NAME) directory is totaly cleaned !"

re					: fclean all

norm				:
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re
