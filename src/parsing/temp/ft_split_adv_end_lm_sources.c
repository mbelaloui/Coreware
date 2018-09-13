/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_adv_end_lm_sources.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:45:23 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 12:46:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	ft_split_adv_end_lm_sources(int index, t_charlist *file,
		t_charlist **comment, t_charlist **ret_file)
{
	int len_line;

	len_line = ft_strlen(file->data);
	if (index)
	{
		ft_cut_add_charlist(file->data, index + 2, len_line, ret_file);
		ft_cut_add_charlist(file->data, 0, index, comment);
	}
	else
		ft_cut_add_charlist(file->data, index + 2, len_line, ret_file);
}
