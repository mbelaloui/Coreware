/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:35:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:14:37 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

t_charlist		*ft_new_charlist(const char *data)
{
	t_charlist	*ret;

	if (!data)
		return (NULL);
	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->data = ft_strdup(data);
	ret->next = NULL;
	return (ret);
}
