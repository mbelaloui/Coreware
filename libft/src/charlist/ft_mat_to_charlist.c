
#include "../../inc/charlist.h"

t_charlist	*ft_mat_to_charlist(char **mat)
{
	t_charlist	*ret;
	int			i;

	i = 0;
	if (!mat)
		return (NULL);
	ret = NULL;
	while (mat[i])
	{
		ft_add_charlist(mat[i], &ret);
		i++;
	}
	return (ret);
}
