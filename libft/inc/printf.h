/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelalou <mbelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:11:55 by mbelalou          #+#    #+#             */
/*   Updated: 2018/10/10 14:10:24 by mbelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include "color.h"

typedef struct	s_flags
{
	int			dash : 1;
	int			plus : 1;
	int			hashtag :1;
	int			zero : 1;
	int			space :1;
	int			apo : 1;
}				t_flags;

typedef struct	s_conversion
{
	int			h : 1;
	char		nbr_h;
	int			l : 1;
	char		nbr_l;
	int			j : 1;
	int			z : 1;
}				t_convert;

typedef struct	s_fotmat
{
	size_t		len_temp;
	t_flags		flags;
	int			min_length;
	int			is_there_min_length : 1;
	int			precision;
	int			is_there_precision : 1;
	t_convert	convertion;
	char		type;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_put_param(va_list *ap, char *str, t_format *format);

void			ft_switch_type(t_format *format, va_list *ap);

int				ft_is_convertion_type(char c);
int				ft_get_parssing_format(char *str, t_format *format);

void			ft_convert_nbr(t_format *format, va_list *ap);
void			ft_convert_nbr_base(t_format *format, va_list *ap);
void			ft_convert_nbr_uns(t_format *format, va_list *ap);
void			ft_convert_pointer(t_format *format, va_list *ap);

void			ft_convert_string(t_format *format, va_list *ap);
void			ft_convert_wchar(t_format *format, va_list *ap);
void			ft_convert_wstring(t_format *format, va_list *ap);
void			ft_convert_char(t_format *format, va_list *ap);

int				is_valid(t_format *format);
void			ft_put_flags(t_flags *flags);
void			ft_put_format(t_format *format);
void			ft_put_convertion(t_convert *convertion);

int				ft_put_buf(const char c, int option);

void			ft_format_init(t_format *format);

uintmax_t		ft_get_uconvertion_size(uintmax_t data, t_convert convert);
intmax_t		ft_get_convertion_size(intmax_t data, t_convert convert);
void			ft_convert_percent(t_format *format, va_list *ap);
void			ft_generat_char_ret(t_format *format, unsigned char temp);

int				ft_put_unbr(uintmax_t nbr, t_format *format);
int				ft_put_nbr(intmax_t nbr, t_format *format);
int				ft_put_str(char *print, intmax_t max_print);
int				ft_fill_buf(intmax_t max_print, char print);

int				ft_get_min_len(char *str, int pt, t_format *format,
		va_list *ap);

#endif
