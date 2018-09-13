/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 11:13:20 by mbelalou          #+#    #+#             */
/*   Updated: 2018/09/13 11:14:25 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/asm.h"

void	check_for_bad_caracter(t_charlist *file)
{
	char *temp;

	if (!(temp = ft_charlist_to_str(file, SPS)))
		ft_error_reading_file(ERROR_EMPTY_FILE);
	if(ft_is_c_in_str(SEP, temp))
		ft_error_reading_file(ERROR_BAD_CHAR_FILE);
	ft_strdel(&temp);
}

t_charlist	*ft_clean_file(t_charlist *file)
{
	char *str_file;
	char *temp;
	t_charlist *ret;

	check_for_bad_caracter(file);
	if (!(str_file = ft_charlist_to_str(file, SEP)))
		return (NULL);
	temp = str_file;
	str_file = ft_extract_simpl_comment(str_file);
	ft_strdel(&temp);
	temp = str_file;
	str_file = ft_extract_ml_comment(str_file);
	ft_strdel(&temp);
	ret = ft_str_to_charlist(str_file, SEP);
	ft_strdel(&str_file);
	return (ret);
}
