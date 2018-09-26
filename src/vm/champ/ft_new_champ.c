/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 10:26:24 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 11:36:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_champ		*ft_new_champ(void)
{
	t_champ	*ret;

	if (!(ret = malloc(sizeof(*ret))))
			ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id = -1;
	ret->name = NULL;
	ret->comment = NULL;
	ret->size = 0;
	ret->src = NULL;
	ret->next = NULL;
	return (ret);
}
