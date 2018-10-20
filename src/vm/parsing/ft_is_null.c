/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:22:01 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/19 12:34:01 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

BOOL	ft_is_null(int fd)
{
	unsigned char	oct[4];
	int				val;

	if (!ft_get_next_oct(fd, &oct))
		ft_error_reading_file(ERROR_READING_FILE);
	val = ft_byts_to_int(oct);
	if (val)
		ft_error_reading_file(ERROR_FORMAT_FILE);
	return (T);
}
