/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fields.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:33:38 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:31:54 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_fields(t_spec *s, char *p, va_list ap)
{
	s->prec = (*p == '.' && s->dot) ? 0 : s->prec;
	s->dot = (*p == '.') ? '1' : s->dot;
	s->to_left = (*p == '-') ? '1' : s->to_left;
	s->show_sign = (*p == '+') ? 1 : s->show_sign;
	s->first_space = (*p == ' ') ? '1' : s->first_space;
	s->fill_zero = (*p == '0'
			&& !s->width && !s->prec) ? '1' : s->fill_zero;
	if (*p == '*' && !s->dot)
	{
		s->width = va_arg(ap, int);
		s->width_init = '1';
		s->err_left = s->width < 0 ? '1' : s->err_left;
	}
	s->to_left = s->width < 0 ? '1' : s->to_left;
	s->width = s->width < 0 ? s->width * -1 : s->width;
	if (*p == '*' && s->dot)
	{
		s->prec = va_arg(ap, int);
		s->prec_init = '1';
		s->error = s->prec < 0 ? '1' : s->error;
	}
}
