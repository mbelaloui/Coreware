/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_inst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 10:56:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/20 12:49:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

t_inst	*ft_new_inst(char *label, char *op, t_charlist *args)
{
	t_inst	*ret;
	int		i;

	if (!(ret = malloc(sizeof(*ret))))
		exit(0);
	ret->label = label;
	ret->opcode = op;
	ret->param = args;
	i = 0;
	while (i < 6)
	{
		ret->size[i] = -1;
		i++;
	}
	ret->add = NULL;
	ret->position = 0;
	return (ret);
}
