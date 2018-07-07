/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_op_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 18:09:57 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/07 18:16:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

void	ft_get_op_tab(t_op *op_tab[NBR_OP])
{
	ft_init_op_tab(op_tab);
	ft_set_param(op_tab);
	ft_set_desc_param(op_tab);
}

/*
** if return (null) --> op dosn't existe ...
*/

t_op	*ft_get_op(t_op *op_tab[NBR_OP], char *str)
{
	int i;

	i = 0;
	while (i < NBR_OP)
	{
		if (!ft_strcmp(op_tab[i]->name, str))
			return (op_tab[i]);
		i++;
	}
	return (NULL);
}

/*
**int		main(void)
**{
**	t_op *op_tab[17];
**	ft_get_op_tab(op_tab);
**		ft_put_op(op_tab);
**	ft_put_typ_param(op_tab);
**  voila pour is type ok
**il suffit de lui en voyer la description de op et le type de parame detecter
**	ft_printf(" hellow %d \n", ft_is_type_ok(op_tab[1], T_REG_P1));
**	return (0);
**}
**int		main()
*/

int		main(int argv, char **argc)
{
	t_op	*op_tab[NBR_OP];
	int		ret;
	t_op	*op;

	ft_get_op_tab(op_tab);
	ft_put_op(op_tab);
	ft_put_desc_param(op_tab);
//	ft_put_typ_param(op_tab);
	if (argv > 1)
	{
		ret = ft_is_name_op(argc[1]);
		ft_printf("ret == %d\n", ret);
		if (ret > -1)
			ft_printf("est une op\n");
		else
			ft_printf("pas une op    <%s>\n", argc[1]);
	}
	op = ft_get_op(op_tab, argc[1]);
	if (ft_is_type_ok(op, T_REG_P3))
	{
		ft_printf("param ok \n");
	}
	else
		ft_printf("param ko \n");
	(void)op;
	ft_dell_op(op_tab);
	return (0);
}
