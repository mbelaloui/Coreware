/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_reading_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:14:43 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/16 11:03:43 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void		ft_error_reading_file(int error)
{
	ft_printf("{red}Error{eoc} ");
	if (ERROR_READING_FILE == error)
		ft_printf("the file doesn't exist\n");
	else if (ERROR_EMPTY_FILE == error)
		ft_printf("the file is empty\n");
	else if (ERROR_BAD_CHAR_FILE == error)
		ft_printf("forbidden char <%c> found in file\n", SEP);
	else
		ft_printf("an error occurred while reading file\n");
	exit(error);
}
