/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:19:16 by dzui              #+#    #+#             */
/*   Updated: 2017/05/13 18:19:18 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>

typedef struct		s_flags
{
	int				i_count;
	int				j_count;
	int				k_count;
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;
	int				i;
	int				counter;
	int				width;
	int				prec;
	int				hh;
	char			perc;
	int				h;
	int				l;
	int				ll;
	int				z;
	int				j;
	int				u;
	int				u_big;
	char			conver;
	int				inv_conv;
	char			*string;
	char			*conversion;
	char			*numbers;
	va_list			arg_ptr;
}					t_flags;

int					ft_printf(char *str, ...);
void				find_flags(char *str, t_flags *fl);
void				struct_def(t_flags *fl);
void				ft_width(char *str, t_flags *fl);
void				ft_precision(char *str, t_flags *fl);
void				ft_conversion(char *str, t_flags *fl);
void				ft_no_minus_string(char *str, t_flags *fl);
void				ft_minus_string(char *str, t_flags *fl);
void				ft_string(t_flags *fl);
void				ft_char(t_flags *fl);
void				ft_char_no_minus(char ch, t_flags *fl);
void				ft_char_minus(char ch, t_flags *fl);
void				ft_numbers_base(t_flags *fl, char conv);
char				*ft_itoa_base_unsigned(t_flags *fl, int base, int nb_case);
void				ft_no_minus_base_16(t_flags *fl, int base, int nb_case);
void				ft_minus_base_16(t_flags *fl, int base, int nb_case);
void				ft_no_minus_base_8(t_flags *fl, int base, int nb_case);
void				ft_minus_base_8(t_flags *fl, int base, int nb_case);
intmax_t			ft_type_signed(t_flags *fl);
uintmax_t			ft_type_unsigned(t_flags *fl);
char				*ft_itoa_base_signed(t_flags *fl, int base, int nb_case);
void				ft_no_minus_base_10(t_flags *fl, int base, int nb_case);
void				ft_minus_base_10(t_flags *fl, int base, int nb_case);
void				ft_addition(const uint32_t symbol, char *wc);
char				*ft_get_wchar(wchar_t symbol);
void				ft_minus_unistring(wchar_t *u_s, t_flags *fl);
void				ft_no_minus_unistring(wchar_t *u_s, t_flags *fl);
void				simple_string(t_flags *fl, char *str);
void				ft_n(t_flags *fl);
void				ft_minus_unistring(wchar_t *s, t_flags *fl);
void				ft_no_minus_unistring(wchar_t *s, t_flags *fl);
void				ft_unistring(t_flags *fl);
int					ft_unistrlen(wchar_t *s);
int					ft_star(t_flags *fl);
void				ft_addition(const uint32_t symbol, char *wc);
void				ft_flags_1(t_flags *fl, char *str);
void				ft_flags_2(t_flags *fl, char *str);
void				ft_flags_4(t_flags *fl, char *str);
int					ft_percent(t_flags *fl, char *str);
void				ft_flags_3(t_flags *fl, char *str);
void				ft_flags_5(t_flags *fl, char *str);
void				ft_start_conversion(int flag, t_flags *fl, char *str);
void				ft_decimal_conver(t_flags *fl, char *str);
void				ft_define_base(char conv, int *base,
								int *nb_case, t_flags *fl);
void				ft_count_width_prec_10(t_flags *fl, char *number);
void				ft_inv_prec_null_10(t_flags *fl, char ch);
void				ft_inv_prec_null_16(t_flags *fl, char ch);
void				ft_minus_base_16_print(t_flags *fl,
											char *number, int nb_case);
void				ft_no_minus_16_hash(t_flags *fl, char *number,
											char ch, int nb_case);
void				ft_no_minus_16_no_hash(t_flags *fl, char *number,
											char ch, int nb_case);
void				ft_count_width_prec_16(t_flags *fl, char *number, char *ch);
void				ft_ival_prec_8(t_flags *fl, char ch);
void				ft_no_minus_8_print(t_flags *fl, char *number, char ch);
void				ft_minus_8_print(t_flags *fl, char *number);
void				ft_make_number(char *res, int nbnb_case);
int					ft_count_digs_signed(intmax_t number, int nb, int base);
int					ft_count_digs_unsigned(uintmax_t number, int nb, int base);
void				ft_set_minus(char *res, int flag, intmax_t number, int *nb);
void				ft_print_width(t_flags *fl, char ch);
void				ft_set_vars(t_flags *fl, char *ch);
void				ft_set_counters_def(t_flags *fl);
void				ft_set_char(t_flags *fl, char *ch);
void				ft_minus_no_zero_10_1(t_flags *fl, char *number);
void				ft_minus_no_zero_10_2(t_flags *fl, char *number);
void				ft_minus_zero_10_1(t_flags *fl, char *number, char ch);
void				ft_minus_zero_10_2(t_flags *fl, char *number, char ch);
void				ft_no_minus_zero_10(t_flags *fl, char *number, char ch);
void				ft_no_minus_no_zero_10(t_flags *fl, char *number);
void				ft_print_no_min_10(t_flags *fl, char *number, char ch);
void				ft_no_minus_zero_10_2(t_flags *fl, char ch);
int					ft_get_index(intmax_t number, int base);
char				*ft_make_zero(void);
void				ft_print_number_8(t_flags *fl, char *number, char ch);
void				ft_count_width_prec_10_no_minus(t_flags *fl, char *number);
void				ft_count_width_prec_10_minus(t_flags *fl, char *number);

#endif
