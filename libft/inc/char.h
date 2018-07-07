/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:06:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/06/09 14:14:16 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

# include "libft.h"

int		ft_chartoint(const char c);
BOOL	ft_isalnum(const char c);
BOOL	ft_isalpha(const char c);
BOOL	ft_isascii(const char c);
BOOL	ft_isblank(const char c);
BOOL	ft_isdigit(const char c);
BOOL	ft_isprint(const char c);
BOOL	ft_isupper(const char c);
BOOL	ft_islower(const char c);
void	ft_putchar(const char c);
void	ft_putchar_fd(const char c, const int fd);
char	ft_tolower(const char c);
char	ft_toupper(const char c);

#endif
