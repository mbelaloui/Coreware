/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:30:36 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:55:32 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	if (!str)
		return (NULL);
	return (ft_strcut(str, start, start + len));
}
