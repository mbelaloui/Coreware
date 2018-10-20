/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:13:13 by mbelalou          #+#    #+#             */
/*   Updated: 2018/05/03 16:25:20 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCHAR_H
# define WCHAR_H

# include "libft.h"

void	ft_putwstr(const wchar_t *str);
char	*ft_wchar_to_string(const wchar_t c, char *ret);
size_t	ft_wstrlen(const wchar_t *s);
size_t	ft_wstringlen(const wchar_t *s);
size_t	ft_wcharlen(const wchar_t wc);

#endif
