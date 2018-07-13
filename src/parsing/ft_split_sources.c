/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sources.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:42:34 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 12:42:55 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_split_sources(int index, t_charlist *file, t_charlist **comment,
		t_charlist **ret_file)
{
	int len_line;

	len_line = ft_strlen(file->data);
	if (index + 1 < len_line)
	{
		ft_cut_add_charlist(file->data, index + 1, len_line, comment);
		ft_cut_add_charlist(file->data, 0, index, ret_file);
	}
	else
		ft_cut_add_charlist(file->data, 0, index, ret_file);
}
