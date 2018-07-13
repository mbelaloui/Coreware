/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_start_ml_comment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:32:00 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 15:12:54 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		ft_get_start_ml_comment(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == COMMENT_CHAR_2 && str[i + 1] == COMMENT_CHAR_3))
			return (i);
		i++;
	}
	return (-1);
}
