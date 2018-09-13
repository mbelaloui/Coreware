/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:45:31 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:28:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lst.h"

t_list	*ft_lstnew(const void *src, size_t size)
{
	t_list *result;

	result = (t_list *)malloc((size + 1) * sizeof(result));
	if (result == NULL)
		return (NULL);
	if (src == NULL)
	{
		result->content = NULL;
		result->content_size = 0;
	}
	else
	{
		result->content = ft_memalloc(size);
		ft_memcpy(result->content, src, size);
		result->content_size = size;
	}
	result->next = NULL;
	return (result);
}
