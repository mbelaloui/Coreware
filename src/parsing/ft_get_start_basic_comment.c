/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_basic_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:40:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 12:41:03 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int			ft_get_start_basic_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR || str[i] == COMMENT_CHAR_1)
			return (i);
		i++;
	}
	return (-1);
}
