/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:05:02 by mbelalou          #+#    #+#             */
/*   Updated: 2018/07/18 11:35:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "libft.h"

# define FIRST		1
# define SECOND		2
# define BOTH		3

typedef struct	s_show
{
	char		buf[SIZE_BUF_SHOW + 1];
	int			pt;
	int			cp;
}				t_show;

size_t			ft_comptword(const char *str, const char separator);
int				ft_fill_elem(int len, char *bit, char *temp_tab, int lim);
char			*ft_format_str(const char *str);
int				ft_getfirstindexword(const char *str, const int idword,
		const char c);
size_t			ft_getlenword(const char *str, const int index, const char c);
intmax_t		ft_gettab_index(const char *tab, const char val);
char			ft_gettab_val(const char *tab, const int index);
char			*ft_getword(const char *s, const int idword,
		const char separator);
int				ft_get_c_in_str(const char *str, const char c);
BOOL			ft_is_c_in_str(const char c, const char *str);
BOOL			ft_isempty(const char *str);
char			*ft_itoa(int nbr);
int				ft_put_buf(const char c, const int option);
void			ft_putendl(const char *str);
void			ft_putendl_fd(const char *str, const int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *str, int fd);
char			*ft_strcat(char *str1, const char *str2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcut(const char *src, const size_t begin,
		const size_t end);
BOOL			ft_strdel(char **str);
char			*ft_strdup(const char *str);
void			ft_strdup_stat(const char *src, char *dest);
int				ft_strequ(const char *str1, const char *str2);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void(*f)(unsigned int, char *));
char			*ft_strjoin(const char *str1, const char *str2);
char			*ft_strjoin_sep(char const *str1, char const *str2,
		const char c);
char			*ft_strjoin_clear(char **str1, char **str2, int del);
size_t			ft_strlcat(char *dest, const char *src, size_t size_dest);
size_t			ft_strlen(const char *str);
char			*ft_strlower(const char *str);
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char			*ft_strncat(char *str1, const char *str2, size_t size_max);
int				ft_strncmp(const char *str1, const char *str2, size_t max_comp);
char			*ft_strncpy(char *dst, const char *src, size_t max_cpy);
int				ft_strnequ(const char *str1, const char *str2, size_t max_comp);
char			*ft_strnew(const size_t size);
char			*ft_strnew_empty(const size_t size);
char			*ft_strnstr(const char *ha, const char *ne, size_t max_comp);
char			*ft_strrchr(const char *str, int c);
char			**ft_strsplit(const char *str, char separator);
char			*ft_strstr(const char *ha, const char *ne);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strtrim(const char *str);
char			*ft_strupper(const char *str);

// remove this fonction
//int		ft_extract_options(char *param, unsigned long *op,
//		BOOL is_option(char), void set_options(char, unsigned long *));

#endif
