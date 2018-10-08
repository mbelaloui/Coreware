/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_url_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:00:27 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/08 14:19:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_url_file		*ft_new_url_file(int num, char *url)
{
	t_url_file	*ret;

	if (!(ret = malloc(sizeof(*ret))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->num = num;
	if (!(ret->url = ft_strdup(url)))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ret->next = NULL;
	return (ret);
}
