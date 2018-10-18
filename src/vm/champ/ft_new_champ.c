/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:26:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/18 09:15:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_champ		*ft_new_champ(int num, int pos)
{
	t_champ	*ret;

	ret = NULL;
	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->num = num;
	ret->pos = pos;
	ret->name = NULL;
	ret->comment = NULL;
	ret->size = 0;
	ret->src = NULL;
	ret->next = NULL;
	return (ret);
}
