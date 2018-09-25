/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_listchamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:17:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/25 20:18:55 by mbelalou         ###   ########.fr       */
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
	ret->champ = champ;
	ft_printf("new {yellow}%s{eoc}\n", champ->name);
	ret = NULL;
	//ft_printf("{ye		llow}%s{eoc}", ret->champ->name);
	return (ret);
}	
