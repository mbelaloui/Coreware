/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:22:07 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 11:23:48 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

int	ft_get_data(char *str, char **data)
{
	int end_def;

	if (str[0] != DEF || (end_def = ft_get_index_end(str)) == -1)
		return (-1);
	*data = ft_strcut(str, 1, end_def - 1);
	return (end_def);
}
