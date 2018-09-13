/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_url_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:52:51 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/13 14:38:15 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/charlist.h"

BOOL	ft_read_url_file(const char *url, t_charlist **file)
{

	if (!url || !file)
		return (F);
	return (ft_read_fd_file(ft_open_r_file(url), file) ? T : F);
}
