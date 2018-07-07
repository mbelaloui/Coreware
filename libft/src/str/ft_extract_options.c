/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:53:16 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/26 11:53:47 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/str.h"

/*
** puis tester si valde ou pas la ont recupr just les options
**(faire le test pour le parammettre de -o out_put.cor
** ici si jamais je laisse cette option)
**
** important voir comment ca ce passe pour les options a la fin de param"
** ajouter une fonction pour affihcer en binaire les options
** une autre plus claire pour voir les options qui sont activer
** ajouter un commentaire pour les entrees et les sorties de
** cette fonction
**
**	return -1 if the options is not reconized
*/

int	ft_extract_options(char *param, unsigned long *op, BOOL is_option(char),
		void set_options(char, unsigned long *))
{
	int index;

	index = 0;
	while (param[index])
	{
		if (param[index] == '-')
		{
			index++;
			if (is_option(param[index]) && param[index + 1] == ' ')
				set_options(param[index], op);
			else
				return (!param[index + 1] ? index + 1 : -1);
			index++;
		}
		else
			return (index);
		index++;
	}
	return (index);
}
