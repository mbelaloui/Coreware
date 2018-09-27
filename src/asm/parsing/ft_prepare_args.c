/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:50:32 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/27 19:19:13 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

char	**ft_prepare_args(char **str, char *name_op, t_op *op, char **args)
{
	char	**tab_args;
	int		i;

	i = 0;
	if (!str[i])
		ft_error_args(ERROR_ARG_NULL, name_op, *args, NULL);
	while (str[i])
		*args = ft_strjoin_clear(args, &str[i++], FIRST);
	if ((*args)[0] == SEPARATOR_CHAR
			|| (*args)[ft_strlen(*args) - 1] == SEPARATOR_CHAR)
		ft_error_args(ERROR_FORMAT_ARG, name_op, *args, NULL);
	tab_args = ft_strsplit(*args, SEPARATOR_CHAR);
	if ((int)ft_matlen(tab_args) != op->nbr_param)
		ft_error_args(ERROR_NBR_ARG, name_op, *args, NULL);

/*	ft_printf("\n\t================================================= \n");
	ft_putmat(tab_args);
	ft_printf("\n\t================================================= \n");
*/
	return (tab_args);
}
