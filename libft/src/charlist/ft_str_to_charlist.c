#include "../../inc/charlist.h"

t_charlist	*ft_str_to_charlist(char *str, char sep)
{
	t_charlist	*ret;
	char		**temp;
	int 		i;

	i = 0;
	if (!ft_strlen(str))
		return (NULL);
	temp = ft_strsplit(str, sep);
	ret = NULL;
	while (temp[i])
	{
		ft_add_charlist(temp[i] ,&ret);
		i++;
	}
	ft_free_mat(&temp);
	return (ret);
}
