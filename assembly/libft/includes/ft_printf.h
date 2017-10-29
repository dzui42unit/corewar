/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 15:33:24 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 14:38:47 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>
# include "libft.h"

typedef struct		s_flags
{
	int				justify_left;
	int				show_sign;
	int				add_space_if_no_sign;
	int				alter_form;
	int				add_zeros;
}					t_flags;

typedef struct		s_format
{
	t_flags			*flags;
	int				min_width;
	int				precision_flag;
	int				precision_value;
	int				length;
	int				type;
}					t_format;

typedef struct		s_string
{
	char			*str;
	int				len;
	struct s_string	*next;
}					t_string;

/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);

/*
** append.c
*/
int					pf_append_filler(char *fmt, t_string **str, int i,
										int chars_p);
int					pf_append_result(char *fmt, va_list *args, t_string **str,
										t_format **tf);
void				pf_append_str(char *fmt, t_string **str, t_format *tf);

/*
** setup.c
*/
t_string			*pf_create_str(char *fmt);
void				pf_fill_string(t_format *tf, char **fmt, void *arg);
int					pf_parse_format(char *fmt, int *chars_p, t_format **tf);

/*
** parse.c
*/
int					pf_get_flags_and_width(char *fmt, t_format *tf, int *i);
int					pf_get_precision(char *fmt, t_format *tf, int *i);
int					pf_get_length(char *fmt, t_format *tf, int *i);
void				pf_get_type(char *fmt, t_format *tf, int *i);

/*
** handlers
*/
void				pf_handle_decimal(char **fmt, t_format *tf, void *arg);
void				pf_handle_unsigned(char **fmt, t_format	*tf, void *arg);
void				pf_handle_octal(char **fmt, t_format *tf, void *arg);
void				pf_handle_hex(char **fmt, t_format *tf, void *arg);
void				pf_handle_binary(char **fmt, t_format *tf, void *arg);
void				pf_handle_char(char **fmt, t_format *tf, void *arg);
void				pf_handle_string(char **fmt, t_format *tf, void *arg);
void				pf_handle_ptr(char **fmt, t_format *tf, void *arg);
void				pf_handle_err(char *fmt, t_string **str, t_format **tf);
void				pf_handle_pct(t_string **str, t_format **tf);
void				pf_handle_precision_2(char *fmt, t_format *tf, char **k,
											char **p);
void				pf_handle_precision_1(char **fmt, t_format *tf,
											unsigned long arg, char **k);
void				pf_handle_width(char *fmt, t_format *tf, char **k,
									char **p);
void				pf_handle_sign(char **fmt, t_format *tf, long arg);
void				pf_handle_space(char **fmt, t_format *tf, char *k);

/*
** advanced_itoa_functions.c
*/
char				*pf_ltoa(long value);
char				*pf_ltoa_base(long value, int base, char *base_str);

/*
** wchar_parse.c
*/
char				*pf_wchar_to_char(wchar_t const n);
char				*pf_gen_wstr(wchar_t *n, int *len);
char				*pf_gen_nwstr(wchar_t *n, int d);

#endif
