/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_listchamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:17:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/26 10:43:34 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/vm.h"

t_listchamp	*ft_new_listchamp(t_champ *champ)
{
	t_listchamp	 *ret;

	if (!(ret = malloc(sizeof(*ret))))
	{
		return(NULL); //c'est proteger dans la fonction qui l'appelle
	}
	ret->champ = ft_new_champ();
	ft_printf("{cyan}je suis la {eoc}\n");
	ret->champ->id = champ->id;
	ft_printf("{cyan} 22222222222222222 {eoc}\n");
	ret->champ->name = ft_strdup(champ->name);
	ft_printf("{cyan}33333333333333   %s{eoc}\n", ret->champ->name);
	ret->champ->comment = ft_strdup(champ->comment);
	ret->champ->size = champ->size;
//	ret->champ->src = champ->src;
//	ret->champ;
	ret = NULL;
	//ft_printf("{ye		llow}%s{eoc}", ret->champ->name);
	return (ret);
}	
