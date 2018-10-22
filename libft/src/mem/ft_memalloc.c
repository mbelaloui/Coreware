/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memlloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:06:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:16:30 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mem.h"

void	*ft_memalloc(const size_t size)
{
	char	*result;

	if (size > 2147483647)
		return (NULL);
	if (!(result = malloc((size + 1) * sizeof(*result))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ft_bzero(result, size + 1);
	return ((void *)result);
}
