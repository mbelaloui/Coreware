/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_url_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:00:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:01:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_url_file		*ft_new_url_file(int id, char *url)
{
	t_url_file	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->id  = id;
	if (!(ret->url = ft_strdup(url)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->next = NULL;
	return (ret);
}
