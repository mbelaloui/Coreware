/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_existe_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:15:15 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:15:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_existe_num(int num, t_url_file *list)
{
	while (list)
	{
		if (num == list->num)
			return (T);
		list = list->next;
	}
	return (F);
}
