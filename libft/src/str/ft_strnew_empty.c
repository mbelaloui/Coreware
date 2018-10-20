/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:47:50 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 12:18:49 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strnew_empty(const size_t size)
{
	char	*result;

	if (size > 2147483647)
		return (NULL);
	if (!(result = malloc((size + 1) * sizeof(*result))))
		ft_error_exe(ERROR_NOT_ENOUGH_MEM);
	ft_memset(result, ' ', size);
	result[size + 1] = '\0';
	return (result);
}
