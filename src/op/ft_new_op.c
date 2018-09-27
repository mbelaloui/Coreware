/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:22:39 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:27:45 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

t_op	*ft_new_op(int mnemonique, char *name, int nbr_param, int cycle)
{
	t_op*ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->mnemonique = mnemonique;
	ret->name = ft_strdup(name);
	ret->nbr_param = nbr_param;
	ret->param = 0;
	ret->cycle = cycle;
	ret->description = NULL;
	ret->desc_param = F;
	ret->size_label = 0;
	return (ret);
}
