/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:56:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:27:53 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lst.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *result;
	t_list *temp;

	if (lst == NULL)
		return (NULL);
	temp = (*f)(lst);
	result = temp;
	lst = lst->next;
	while (lst)
	{
		temp->next = (*f)(lst);
		temp = temp->next;
		lst = lst->next;
	}
	temp = NULL;
	return (result);
}
