/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_add_charlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:11:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/14 16:12:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

/*
** enlever les comments si ont ne veut pas prendre les comments comme ils sont
*/

BOOL	ft_cut_add_charlist(char *src, int start, int max_size,
		t_charlist **dest)
{
	char	*line;

	if (!src || start > max_size || max_size == 0 || !dest)
		return (F);
	line = ft_strcut(src, start, max_size);
	if (!line)
		return (F && ft_strdel(&line));
	ft_add_charlist(line, dest);
	ft_strdel(&line);
	return (T);
}
