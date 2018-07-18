/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purification_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:51:11 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 13:53:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
** a terminer ajouter les commentaires dans une liste
** split la fonction par apport a chaque type de comment
*/

static void	manage_sep(char **ret)
{
	char *to_del;

	to_del = *ret;
	*ret = ft_strjoin(*ret, "\n");
	ft_strdel(&to_del);
}

static int	manage_simple_comment(char *file, t_charlist **comment)
{
	int i;
	int start;

	i = 1;
	if (file[i] == COMMENT_CHAR_2)
		start = 2;
	else
		start = 1;
	while (file[i] && file[i] != SEP)
		i++;
	ft_cut_add_charlist(file, start, i, comment);
	return (i);
}

static int	manage_ml_comment(char *file, t_charlist **comment)
{
	int i;

	i = 2;
	while (file[i] && file[i] != '*' && file[i + 1] != '/')
		i++;
	ft_cut_add_charlist(file, 2, i, comment);
	if (file[i] && file[i] == '*' && file[i + 1] == '/')
		i += 2;
	return (i);
}

static int	manage_simple_source(char *file, char **ret)
{
	char	*to_add;
	char	*to_del;
	int		index;

	index = ft_get_index_end_line(file);
	to_add = ft_strcut(file, 0, index);
	to_del = *ret;
	*ret = ft_strjoin(*ret, to_add);
	ft_strdel(&to_add);
	ft_strdel(&to_del);
	return (index);
}

char		*ft_purification_file(char *file, t_charlist **comment)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_strnew(ft_strlen(file));
	while (file[i])
	{
		if (file[i] == SEP && i++)
			manage_sep(&ret);
		else if (file[i] == COMMENT_CHAR
				|| file[i] == COMMENT_CHAR_1
				|| (file[i] && file[i] == COMMENT_CHAR_2
					&& file[i + 1] == COMMENT_CHAR_2))
			i += manage_simple_comment(file + i, comment);
		else if (file[i] && file[i] == '/' && file[i + 1] == '*')
			i += manage_ml_comment(file + i, comment);
		else
			i += manage_simple_source(file + i, &ret);
	}
	return (ret);
}
