/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_advenced_comment.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:47:25 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 16:45:06 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** (void) ret_file;
** (void)comment;
*/

static t_charlist	*get_linecomment(t_charlist *file,
		t_charlist **comment, t_charlist **ret_file, int end)
{
	int start;

	start = ft_get_start_ml_comment(file->data);
	ft_printf("/**************************************************\\ \n");
	if (ft_isempty(ft_strcut(file->data, start + 2, end)))
	{
		ft_printf("vide prendre la partie gauche et droite et"
				"les mettre dans la meme line\n");
		ft_printf("avant start = <%d> [%s]", start,
			ft_strcut(file->data, 0, start));
		ft_printf("apres end   = <%d> [%s]\n",
			end, ft_strcut(file->data, end + 2, ft_strlen(file->data)));
	}
	else
	{
		ft_printf("avant start = <%d> [%s]\n",
				start, ft_strcut(file->data, 0, start));
		ft_printf("start = <%d>  [%s]\n",
				start, ft_strcut(file->data, start + 2, end));
		ft_printf("apres end   = <%d> [%s]\n",
				end, ft_strcut(file->data, end + 2, ft_strlen(file->data)));
	}

	(void) comment;
	(void) ret_file;

	return (file);
}

t_charlist			*ft_manage_advenced_comment(t_charlist *file,
		t_charlist **comment, t_charlist **ret_file)
{
	int		index;

	if ((index = ft_get_end_ml_comment(file->data)) > -1)
		return (get_linecomment(file, comment, ret_file, index));
	index = ft_get_end_ml_comment(file->data);
	ft_split_adv_sources(index + 1, file, comment, ret_file);
	file = file->next;
	while (file)
	{
		if ((index = ft_get_end_ml_comment(file->data)) > -1)
		{
			ft_split_adv_end_lm_sources(index, file, comment, ret_file);
			break ;
		}
		else
			ft_split_adv_sources(index, file, comment, ret_file);
		file = file->next;
	}
	return (file);
}
