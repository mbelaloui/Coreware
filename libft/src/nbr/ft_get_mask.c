/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:26:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 11:42:33 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

char	*ft_get_mask(int id_mask, char *oct)
{
	ft_memset(oct, ' ', 8);
	if (id_mask == 1)
		ft_strdup_stat("10xxxxxx", oct);
	if (id_mask == 2)
		ft_strdup_stat("110xxxxx", oct);
	if (id_mask == 3)
		ft_strdup_stat("1110xxxx", oct);
	if (id_mask == 4)
		ft_strdup_stat("11110xxx", oct);
	return (oct);
}
