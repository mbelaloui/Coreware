/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:34:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 10:27:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/lst.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst && *f)
	{
		f(lst);
		lst = lst->next;
	}
}
