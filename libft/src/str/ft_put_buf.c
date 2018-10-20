/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:29:12 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/11 10:29:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

static int		clean(t_show *show)
{
	(*show).cp = 0;
	return (0);
}

static int		rest(t_show *show)
{
	(*show).cp = 0;
	(*show).pt = 0;
	return (0);
}

int				ft_put_buf(const char c, const int option)
{
	static t_show show;

	if (option == LEN_BUF)
		return (show.cp);
	if (option == RESET)
		return (rest(&show));
	if (option == CLEAN_BUF)
		return (clean(&show));
	if (option == EOL)
		write(1, show.buf, show.pt);
	else
	{
		if (show.pt == SIZE_BUF_SHOW)
		{
			write(STD_OUT, show.buf, show.pt);
			show.pt = 0;
		}
		show.buf[show.pt] = c;
		show.pt++;
		if (option != ING)
			show.cp += 1;
	}
	return (show.cp);
}
