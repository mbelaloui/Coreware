/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:21:33 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 15:16:26 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wchar.h"

static char	*convert_delta_char_to_string(const wchar_t c, char *ret)
{
	char	temp_tab[SIZE_TAB_CONV];
	char	oct[9];
	int		len;

	ft_memset(temp_tab, ' ', sizeof(temp_tab) - 1);
	ft_decimal_to_base_stat(temp_tab, (unsigned)c, BIN, LOWER);
	len = ft_strlen(temp_tab);
	ret[4] = '\0';
	ft_get_mask(1, oct);
	len = ft_fill_elem(len, oct, temp_tab, 1);
	ret[3] = ft_base_to_decimal(oct, 2);
	ft_get_mask(1, oct);
	len = ft_fill_elem(len, oct, temp_tab, 1);
	ret[2] = ft_base_to_decimal(oct, 2);
	ft_get_mask(1, oct);
	len = ft_fill_elem(len, oct, temp_tab, 1);
	ret[1] = ft_base_to_decimal(oct, 2);
	ft_get_mask(4, oct);
	len = ft_fill_elem(len, oct, temp_tab, 4);
	ret[0] = ft_base_to_decimal(oct, 2);
	return (ret);
}

static char	*convert_gamma_char_to_string(const wchar_t c, char *ret)
{
	char	temp_tab[SIZE_TAB_CONV];
	char	oct[9];
	int		len;

	if (c > 55295 && c < 57344)
		ret[0] = '\0';
	else
	{
		ft_memset(temp_tab, ' ', sizeof(temp_tab) - 1);
		ft_decimal_to_base_stat(temp_tab, (unsigned)c, BIN, LOWER);
		len = ft_strlen(temp_tab);
		ret[3] = '\0';
		ft_get_mask(1, oct);
		len = ft_fill_elem(len, oct, temp_tab, 1);
		ret[2] = ft_base_to_decimal(oct, 2);
		ft_get_mask(1, oct);
		len = ft_fill_elem(len, oct, temp_tab, 1);
		ret[1] = ft_base_to_decimal(oct, 2);
		ft_get_mask(3, oct);
		len = ft_fill_elem(len, oct, temp_tab, 3);
		ret[0] = ft_base_to_decimal(oct, 2);
	}
	return (ret);
}

static char	*convert_beta_char_to_string(const wchar_t c, char *ret)
{
	char	temp_tab[SIZE_TAB_CONV];
	char	oct[9];
	int		len;

	ft_memset(temp_tab, ' ', sizeof(temp_tab) - 1);
	ft_decimal_to_base_stat(temp_tab, (unsigned)c, BIN, LOWER);
	len = ft_strlen(temp_tab);
	ret[2] = '\0';
	ft_get_mask(1, oct);
	len = ft_fill_elem(len, oct, temp_tab, 1);
	ret[1] = ft_base_to_decimal(oct, 2);
	ft_get_mask(2, oct);
	len = ft_fill_elem(len, oct, temp_tab, 2);
	ret[0] = ft_base_to_decimal(oct, 2);
	return (ret);
}

static char	*convert_alpha_char_to_string(const wchar_t c, char *ret)
{
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char		*ft_wchar_to_string(const wchar_t c, char *ret)
{
	ft_memset(ret, ' ', 5);
	if (c >= 0x11ffff || c == 0xd800)
	{
		ret[0] = '\0';
		return (ret);
	}
	else if (c > 0xFFFF)
		convert_delta_char_to_string(c, ret);
	else if (c > 0x7FF)
		convert_gamma_char_to_string(c, ret);
	else if (c > 0x7F)
		convert_beta_char_to_string(c, ret);
	else
		convert_alpha_char_to_string(c, ret);
	return (ret);
}
