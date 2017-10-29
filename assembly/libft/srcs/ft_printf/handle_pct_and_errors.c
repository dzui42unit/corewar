/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pct_and_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozabara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:19:03 by ozabara           #+#    #+#             */
/*   Updated: 2017/03/16 14:28:44 by ozabara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_handle_err(char *fmt, t_string **str, t_format **tf)
{
	char	*p;
	char	*t;
	char	*n;

	if ((*tf)->min_width > 0)
	{
		p = ft_strnew((*tf)->min_width - 1);
		if ((*tf)->flags->add_zeros && !((*tf)->flags->justify_left))
			p = ft_memset(p, '0', (*tf)->min_width - 1);
		else
			p = ft_memset(p, ' ', (*tf)->min_width - 1);
	}
	else
		p = ft_strdup("");
	n = ft_strnew(2);
	n[0] = fmt[0];
	t = (*tf)->flags->justify_left ? ft_strjoin(n, p) : ft_strjoin(p, n);
	pf_append_str(t, str, *tf);
	ft_strdel(&p);
	ft_strdel(&n);
	ft_strdel(&t);
	free((*tf)->flags);
	free(*tf);
}

void	pf_handle_pct(t_string **str, t_format **tf)
{
	char	*t;
	char	*p;
	char	*s;

	s = ft_strnew(2);
	s[0] = '%';
	if ((*tf)->min_width > 0)
	{
		p = ft_strnew((*tf)->min_width - 1);
		if ((*tf)->flags->add_zeros && !((*tf)->flags->justify_left))
			p = ft_memset(p, '0', (*tf)->min_width - 1);
		else
			p = ft_memset(p, ' ', (*tf)->min_width - 1);
		t = ft_strdup(s);
		ft_strdel(&s);
		s = ((*tf)->flags->justify_left) ? ft_strjoin(t, p) : ft_strjoin(p, t);
		ft_strdel(&t);
		ft_strdel(&p);
	}
	pf_append_str(s, str, *tf);
	free((*tf)->flags);
	free(*tf);
	ft_strdel(&s);
}
