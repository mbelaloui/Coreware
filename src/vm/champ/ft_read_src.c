/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_src.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:42:54 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/22 13:43:57 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

char	*ft_read_src(int fd, int size)
{
	unsigned char	buf[1];
	char			*src;
	int				i;

	i = 0;
	src = ft_strnew(size);
	while (i < size)
	{
		if (!read(fd, &buf, 1))
			ft_error_reading_file(ERROR_READING_FILE);
		src[i] = buf[0];
		i++;
	}
	if (read(fd, &buf, 1))
		ft_error_reading_file(ERROR_MAGIC_NUM);
	return (src);
}
