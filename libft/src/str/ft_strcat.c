/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:47:26 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 13:17:42 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

char	*ft_strcat(char *str1, const char *str2)
{
	ft_memcpy((str1 + ft_strlen(str1)), str2, ft_strlen(str2) + 1);
	return ((char *)str1);
}
