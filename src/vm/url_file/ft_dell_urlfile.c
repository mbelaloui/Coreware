/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_urlfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:03:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:04:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_dell_urlfile(t_url_file **to_dell)
{
	if (!to_dell || !(*to_dell))
		return (F);
	ft_strdel(&(*to_dell)->url);
	free(*to_dell);
	return (T);
}
