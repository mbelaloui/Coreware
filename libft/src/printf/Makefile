# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 21:48:22 by mbelalou          #+#    #+#              #
#    Updated: 2018/06/05 12:45:31 by mbelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

FLAGES			= -Wall -Wextra -Werror -c

DIR_COLOR		= color
SRC_COLOR		= ft_inittabcolor.c ft_setcyan.c ft_setred.c ft_get_color.c\
				  ft_put_color.c ft_setgreen.c ft_setwhite.c ft_gettabcolor.c\
				  ft_setblue.c ft_setmagenta.c ft_setyellow.c
SRCS_COLOR		= $(addprefix $(DIR_COLOR)/, $(SRC_COLOR))

DIR_FORMAT		= format
SRC_FORMAT		= ft_format_init.c ft_put_flags.c ft_put_convertion.c\
				  ft_put_format.c
SRCS_FORMAT		= $(addprefix $(DIR_FORMAT)/, $(SRC_FORMAT))

DIR_PARSING		= parsing
SRC_PARSING		= ft_get_parssing_format.c ft_put_param.c\
				  ft_is_conversion_type.c ft_switsh_type.c ft_get_min_len.c
SRCS_PARSING	= $(addprefix $(DIR_PARSING)/, $(SRC_PARSING))

DIR_PUT			= put
SRC_PUT			= ft_fill_buf.c ft_put_nbr.c ft_put_str.c ft_put_unbr.c
SRCS_PUT		= $(addprefix $(DIR_PUT)/, $(SRC_PUT))

DIR_CONV_TYPE	= type_convertion
SRC_CONV_TYPE	= ft_convert_char.c ft_convert_string.c ft_convert_wstring.c\
				  ft_convert_nbr.c ft_convert_wchar.c ft_get_convertion_size.c\
				  ft_convert_nbr_base.c ft_convert_nbr_uns.c\
				  ft_convert_pointer.c ft_get_uconvertion_size.c
SRCS_CONV_TYPE	= $(addprefix $(DIR_CONV_TYPE)/, $(SRC_CONV_TYPE))

INC_DIR			= ../../inc/

OBJS_DIR		= objects/

SRC_PRINTF		= ft_printf.c

SRC				= $(SRCS_PUT) $(SRCS_COLOR) $(SRC_PRINTF) $(SRCS_FORMAT)\
				  $(SRCS_PARSING) $(SRCS_CONV_TYPE)

OBJ				= $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

RED				= \033[31m
YELLO			= \033[33m
WHITE			= \033[37m
BIP				= \a

all				: $(NAME)

$(NAME)			: $(SRC) $(OBJS_DIR) $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "$(YELLO)$(NAME) has been successfully created !$(BIP)$(WHITE)."

$(OBJS_DIR)%.o	: %.c $(INC_DIR)
		@echo "$< ... $(GREEN) compiled $(WHITE)"
		@echo "\033[1A \033[2K \033[A"
		@gcc $(FLAGES) $< -o $@ -I $(INC_DIR)

$(OBJS_DIR)		:
		@mkdir -p $(OBJS_DIR);
		@mkdir -p $(OBJS_DIR)/$(DIR_COLOR);
		@mkdir -p $(OBJS_DIR)/$(DIR_FORMAT);
		@mkdir -p $(OBJS_DIR)/$(DIR_PARSING);
		@mkdir -p $(OBJS_DIR)/$(DIR_PUT);
		@mkdir -p $(OBJS_DIR)/$(DIR_CONV_TYPE);

clean			:
		@rm -fr $(OBJS_DIR)
		@echo "$(RED)cleaned the ft_printf binary files$(WHITE)."

fclean			:
		@rm -fr $(OBJS_DIR)
		@rm -f $(NAME)
		@echo "$(RED)cleaned the ft_printf directory$(WHITE)."

re				: fclean all

.PHONY : all clean fclean re
