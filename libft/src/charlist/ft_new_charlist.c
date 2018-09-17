/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_charlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:35:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/28 18:36:07 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

t_charlist		*ft_new_charlist(const char *data)
{
	t_charlist	*ret;

	if (!data || !(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->data = ft_strdup(data);
	ret->next = NULL;
	return (ret);
}
