/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 10:26:42 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/10 21:11:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/nbr.h"

static int		extraire_nbt(unsigned char *str, unsigned long long nbr)
{
	int				pt;
	int				bool_valide;

	pt = 0;
	bool_valide = 1;
	while (str[pt] != '\0')
	{
		if (ft_isdigit(str[pt]))
		{
			nbr = str[pt] - 48 + (nbr * 10);
		}
		else
		{
			if (bool_valide)
				return (nbr);
			else
				return (0);
		}
		pt++;
	}
	return ((int)nbr);
}

int				ft_atoi(const char *str)
{
	unsigned char		*str_t;
	unsigned long long	nbr;
	int					pt;
	long				signe;

	str_t = (unsigned char *)str;
	pt = 0;
	nbr = 0;
	signe = 1;
	while ((str_t[pt] != '\0') && (str_t[pt] < 33) && (str_t[pt] != '\e'))
		pt++;
	if ((str_t[pt] == '-') || (str_t[pt] == '+'))
	{
		if ((str_t[pt + 1] != '-') && (str_t[pt + 1] != '+'))
			signe = (str_t[pt] == '-') ? -1 : 1;
	}
	else
	{
		if (ft_isdigit(str_t[pt]))
			nbr = str_t[pt] - 48 + (nbr * 10);
		else
			return (0);
	}
	nbr = extraire_nbt(&str_t[++pt], nbr);
	return ((int)(nbr * signe));
}
