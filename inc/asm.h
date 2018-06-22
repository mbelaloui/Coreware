#ifndef ASM_H
# define ASM_H

# include "../libft/inc/libft.h"

# define ERROR_NO_PARAM -1

typedef	struct		s_instruction
{
	char		*label;
	char		*opcode;
	t_charlist	*param;
}			t_instruction;


typedef struct		s_player
{
	char		*name;
	t_charlist	*comment;
	t_instruction	*instructioms;
}			t_player;



#endif
