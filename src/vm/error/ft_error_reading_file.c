/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_reading_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:03:30 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 14:27:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

void	ft_error_reading_file(int error)
{
	ft_printf("{red}Error reading file {eoc}");
	if (error == ERROR_FORMAT_FILE)
		ft_printf("the head file is not well formated\n");
	else if (error == ERROR_READING_FILE)
		ft_printf("<head part> reaching unexpecting eof\n");
	else if (error == ERROR_MAGIC_NUM)
		ft_printf("the file is corrupt\n");
	else if (error == ERROR_SIZE_FILE)
	{
		ft_printf("the size of the champions must be less than "
				" %d\n", CHAMP_MAX_SIZE);
	}
	exit(error);
}
