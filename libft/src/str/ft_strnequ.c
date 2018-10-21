/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:35:38 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:47:36 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

int		ft_strnequ(const char *str1, const char *str2, size_t max_comp)
{
	if (!str1 || !str2)
		return (0);
	return ((ft_strncmp(str1, str2, max_comp) == 0) ? 1 : 0);
}
