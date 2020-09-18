/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:14:41 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:30:05 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int				print_zero(t_spec *spec)
{
	if ((spec->width_init && spec->width && !spec->dot)
		|| (spec->prec_init && spec->prec && spec->dot)
		|| (!spec->width_init && !spec->prec_init && !spec->dot)
		|| (spec->dot && spec->error))
		return (ft_print_char('0', 1));
	return (0);
}

int						render_arg_addr(t_spec *spec, va_list ap)
{
	unsigned long long	number;
	int					strlen;
	int					fill_width;
	int					i;

	strlen = 0;
	number = va_arg(ap, unsigned long long);
	spec->width = !spec->width ? spec->prec : spec->width;
	to_base_cnt(number, 16, &strlen);
	strlen = !number ? 2 : strlen;
	fill_width = spec->width - strlen - 2;
	spec->prec = spec->prec > strlen ? spec->prec - strlen : 0;
	fill_width -= (!number && spec->prec_init && spec->prec > 0) ? 1 : 0;
	fill_width += (!number && !spec->prec_init && spec->dot) ? 1 : 0;
	fill_width += (!number && spec->width && !spec->prec_init) ? 1 : 0;
	spec->prec += (!number && spec->dot && spec->prec) ? 1 : 0;
	i = (!spec->to_left) ? ft_print_char(' ', fill_width) : 0;
	fill_width -= i;
	i += ft_print_char('0', 1) + ft_print_char('x', 1);
	i += (number == 0) ? print_zero(spec) : 0;
	i += ft_print_char('0', spec->prec) + ft_to_base(number, 16, 0, &i);
	i += (spec->to_left) ? ft_print_char(' ', fill_width) : 0;
	return (i);
}
