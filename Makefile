# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 12:33:04 by mbelalou          #+#    #+#              #
#    Updated: 2018/10/19 19:51:06 by mbelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM			= asm
NAME_VM				= corewar

NAME_VM_CORE		= virtual machine

ASM					= assembler
CORE_WAR			= core war

FLAGES				= -Wall -Wextra -Werror -c


DIR_PARSING_VM		= vm/parsing
SRC_PARSING_VM		= ft_check_signature.c ft_get_next_oct.c ft_get_vm_magic.c\
					  ft_get_vm_name.c ft_get_vm_size.c ft_is_null.c\
					  ft_get_vm_comment.c ft_get_vm_src.c ft_init_option_vm.c\
					  ft_get_size_param.c ft_manage_p3.c ft_manage_p2.c\
					  ft_manage_p1.c ft_manage_param.c ft_get_value_op.c\
					  ft_handle_op_dump.c ft_extract_vm_op.c ft_search_for_op.c\
					  ft_manage_vm_url.c ft_get_url.c ft_handle_op_n.c\
					  ft_get_id_champ.c
SRCS_PARSING_VM		= $(addprefix $(DIR_PARSING_VM)/, $(SRC_PARSING_VM))

DIR_ERROR_VM		= vm/error
SRC_ERROR_VM		= ft_error_reading_file.c ft_error_param_vm.c
SRCS_ERROR_VM		= $(addprefix $(DIR_ERROR_VM)/, $(SRC_ERROR_VM))

DIR_CHAMP_VM		= vm/champ
SRC_CHAMP_VM		= ft_dell_champ.c ft_put_raw_src_champ.c ft_manage_opr.c\
					  ft_read_champ_file.c ft_put_champ.c\
					  ft_put_inst_src_vm.c ft_read_src.c ft_new_champ.c\
					  ft_add_bgn_champ.c ft_put_listchamp.c ft_add_end_champ.c\
					  ft_put_list_champ.c
SRCS_CHAMP_VM		= $(addprefix $(DIR_CHAMP_VM)/, $(SRC_CHAMP_VM))

DIR_INST_VM			= vm/inst
SRC_INST_VM			= ft_add.c ft_and.c ft_ld.c ft_ldi.c ft_lld.c ft_null.c\
					  ft_sti.c ft_xor.c ft_add_vm_instlist.c ft_fork.c\
					  ft_lfork.c ft_lldi.c ft_or.c ft_str_to_list_inst.c\
					  ft_zjmp.c ft_aff.c ft_init_tab_instruction.c ft_live.c\
					  ft_new_vm_inst.c ft_st.c ft_sub.c ft_read_indirect.c\
					  ft_set_color_inst.c
SRCS_INST_VM		= $(addprefix $(DIR_INST_VM)/, $(SRC_INST_VM))

DIR_PRINTING_VM		= vm/printing
SRC_PRINTING_VM		= ft_put_usage_vm.c ft_put_help_vm.c ft_put_vm.c ft_put_mem.c\
					  ft_dump.c					  
SRCS_PRINTING_VM	= $(addprefix $(DIR_PRINTING_VM)/, $(SRC_PRINTING_VM))

DIR_URL_FILE		= vm/url_file
SRC_URL_FILE		= ft_new_url_file.c ft_add_urlfilelist.c ft_dell_urlfile.c\
					  ft_dell_bgn_urlfile.c ft_dell_list_urllist.c\
					  ft_put_url_file.c ft_get_prev_num_urlfile.c ft_existe_num.c\
					  ft_size_url_champ.c
SRCS_URL_FILE		= $(addprefix $(DIR_URL_FILE)/, $(SRC_URL_FILE))

DIR_PROCESS_VM		= vm/process
SRC_PROCESS_VM		= ft_add_process.c ft_dell_list_process.c ft_init_process.c\
					ft_new_process.c ft_put_process.c ft_get_next_instuction.c\
					ft_process_desc_ok.c ft_process_desc_ko.c\
					ft_check_survivor.c ft_copie_process.c\
					ft_kill_process.c #ft_get_total_live.c
SRCS_PROCESS_VM		= $(addprefix $(DIR_PROCESS_VM)/, $(SRC_PROCESS_VM))

DIR_OPR_VM			= vm/opr
SRC_OPR_VM			= ft_get_size_type.c ft_put_opr_exe.c ft_set_size_arg.c\
						ft_set_desc_arg.c ft_set_vale_arg.c 
SRCS_OPR_VM			= $(addprefix $(DIR_OPR_VM)/, $(SRC_OPR_VM))

DIR_RUN_VM			= vm/run
SRC_RUN_VM			= ft_dell_vm.c ft_init_vm.c  vm_exe.c ft_init_mem.c\
						ft_fight.c ft_rest_color.c ft_put_winer.c
SRCS_RUN_VM			= $(addprefix $(DIR_RUN_VM)/, $(SRC_RUN_VM))

DIR_OP				= op
SRC_OP				= ft_dell_op.c ft_get_nbr_param.c ft_get_type_param.c\
					  ft_is_type_ok.c ft_put_op.c ft_put_type_param.c\
					  ft_set_size_label.c ft_get_cycle.c ft_get_op.c\
					  ft_init_op_tab.c ft_new_op.c ft_put_op_param.c\
					  ft_set_desc_param.c ft_get_name.c ft_get_op_tab.c\
					  ft_is_name_op.c ft_put_desc_param.c ft_put_size_label.c\
					  ft_set_param.c ft_free_optab.c\
					  ft_is_str_direct.c ft_is_str_indirect.c ft_is_str_register.c\
					  ft_is_str_label.c ft_is_str_label_param.c\
					  ft_is_need_desc_op.c ft_put_type_arg.c
SRCS_OP				= $(addprefix $(DIR_OP)/, $(SRC_OP))

DIR_PARSING_ASM		= asm/parsing
SRC_PARSING_ASM		= ft_manage_url.c ft_extract_simple_comment.c\
					  ft_extract_ml_comment.c ft_clean_file.c\
					  ft_skip_spaces.c ft_get_index_end.c ft_get_data.c\
					  ft_extraire_head_info.c ft_get_type_args.c\
					  ft_prepare_args.c ft_extract_source.c ft_is_option.c\
					  ft_set_asm_options.c ft_extract_asm_options.c\
					  ft_init_asm_option.c ft_extract_info_player.c
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
SRC_RUN_ASM			= asm_exe.c
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
					  ft_put_src.c ft_make_out_put.c ft_translate_player.c\
					  ft_get_arg_translat.c
SRCS_PLAYER_ASM		= $(addprefix $(DIR_PLAYER_ASM)/, $(SRC_PLAYER_ASM))


DIR_GRAPHIC			= vm/graphic
SRC_GRAPHIC			= ft_init_windows.c init_win_player.c ft_print_visu.c
SRCS_GRAPHIC		= $(addprefix $(DIR_GRAPHIC)/, $(SRC_GRAPHIC))

#DIR_		=
#SRC_		=
#SRCS_		= $(addprefix $(DIR_)/, $(SRC_))

INC_DIR				= inc/

OBJS_DIR			= bin/
OBJS_DIR_ASM		= bin_asm/
OBJS_DIR_VM			= bin_vm/

LIBFT_DIR			= libft

LIBFT				= libft.a

SRCS_ASM			= $(SRCS_PARSING_ASM) $(SRCS_ERROR_ASM)\
					  $(SRCS_OP) $(SRCS_PRINTING_ASM) $(SRCS_INST_ASM)\
					  $(SRCS_PLAYER_ASM) $(SRCS_SYMBOLE_ASM) $(SRCS_LABEL_ASM)\
					  $(SRCS_RUN_ASM)

SRCS_VM				= $(SRCS_RUN_VM) $(SRCS_OP) $(SRCS_CHAMP_VM)\
					  $(SRCS_PARSING_VM) $(SRCS_ERROR_VM) $(SRCS_INST_VM)\
					  $(SRCS_PRINTING_VM) $(SRCS_URL_FILE) $(SRCS_PROCESS_VM)\
					  $(SRCS_OPR_VM) $(SRCS_GRAPHIC)

RED					= \033[31m
GREEN				= \033[32m
YELLO				= \033[33m
WHITE				= \033[37m
BIP					= \a

OBJS_ASM			= $(addprefix $(OBJS_DIR), $(SRCS_ASM:.c=.o))
OBJS_VM				= $(addprefix $(OBJS_DIR), $(SRCS_VM:.c=.o))

all					: $(NAME_ASM) $(NAME_VM)

$(NAME_ASM)			: $(LIBFT) $(OBJS_DIR_ASM) $(OBJS_ASM)
	@gcc $(OBJS_ASM) -L $(LIBFT_DIR) -lft -fsanitize=address -o $(NAME_ASM)
	@#gcc $(OBJS_ASM) -L $(LIBFT_DIR) -lft -o $(NAME_ASM)
	@echo "$(GREEN)$(ASM) has been successfully created !$(WHITE)."
	@#say "$(ASM) has been successfully created !"

$(NAME_VM)			: $(LIBFT) $(OBJS_DIR_VM) $(OBJS_VM)
	@gcc $(OBJS_VM) -L $(LIBFT_DIR) -lft -fsanitize=address -lncurses -o $(NAME_VM)
	@#gcc $(OBJS_VM) -L $(LIBFT_DIR) -lft -o $(NAME_VM)
	@echo "$(GREEN)$(NAME_VM_CORE) has been successfully created !$(WHITE)."
	@#say "$(NAME_VM_CORE) has been successfully created !"

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
	@mkdir -p $(OBJS_DIR)$(DIR_RUN_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_PROCESS_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_OP);
	@mkdir -p $(OBJS_DIR)$(DIR_INST_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_CHAMP_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_PRINTING_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_URL_FILE);
	@mkdir -p $(OBJS_DIR)$(DIR_OPR_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_PARSING_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_ERROR_VM);
	@mkdir -p $(OBJS_DIR)$(DIR_GRAPHIC);
	
clean				:
	@clear
	@make -C $(LIBFT_DIR) clean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(CORE_WAR) binary files$(WHITE)."
	@#say "cleaned the $(CORE_WAR) binary files."

fclean				:
	@clear
	@make -C $(LIBFT_DIR) fclean
	@rm -fr $(OBJS_DIR)
	@echo "$(RED)cleaned the $(NAME_ASM) file$(WHITE)."
	@rm -f $(NAME_ASM) $(NAME_VM)
	@echo "$(GREEN)the $(CORE_WAR) directory is totaly cleaned !!$(WHITE)."
	@#say "the $(CORE_WAR) directory is totaly cleaned !"

re					: fclean all

norm				:
	@norminette | grep -B 1 "Error"

.PHONY : all clean fclean re
