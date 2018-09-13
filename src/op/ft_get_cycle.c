/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:17:28 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/12 17:11:17 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/op.h"

/*
**	donner une op a la fonction qui retourne le nbr de cycle pour exe l'op
**
** peut evoluer dans ce sense
** paramettres d'entre un (id de l'op) +  la table // ou la table en static
** retourne le nbr de cycle de l'op
*/

int	ft_get_cycle(t_op *op_tab)
{
	return (op_tab->cycle);
}
