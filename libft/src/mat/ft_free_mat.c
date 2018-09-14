/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:34:44 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/11 21:02:29 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mat.h"

void	ft_free_mat(char ***mat)
{
	int i;

	i = 0;
	while ((*mat)[i])
	{
		ft_strdel(&(*mat)[i]);
		i++;
	}
	free(*mat);
}
