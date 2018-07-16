#include "../../inc/asm.h"

BOOL    is_stop_char(char *str)
{
	if (str[0] == COMMENT_CHAR || str[0] == COMMENT_CHAR_1
			|| str[0] == SEP)
		return (T);
	if (str[0] == COMMENT_CHAR_2 && (str[1] == COMMENT_CHAR_3
				|| str[1] == COMMENT_CHAR_2))
		return (T);
	return (F);
}

int     ft_get_index_end_line(char *str)
{
	int i = 0;

	while (str[i] && !is_stop_char(str + i))
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != DELIMITEUR)
				i++;

		}
		if (str[i])
			i++;
	}
	return (i);
}
