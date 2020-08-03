/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_base16.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 02:03:55 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/30 22:04:18 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						render_arg_base16(t_spec *spec, va_list ap)
{
	unsigned long long	num;
	int					strlen;
	int					fill_width;
	int					i;
	char				fill;

	num = va_arg(ap, unsigned long long);
	to_base_cnt(num, 16, &strlen);
	strlen = num == 0 && !spec->dot ? 1 : strlen;
	fill = (!spec->prec_init && !spec->to_left && spec->fill_zero) ? '0' : ' ';
	fill_width = spec->width - strlen;
	fill_width += (!num && (spec->dot)) ? 1 : 0;
	spec->prec += (!num && (spec->dot && spec->prec)) ? 1 : 0;
	spec->prec -= strlen;
	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
	i = (!spec->to_left) ? ft_print_char(fill, fill_width) : 0;
	fill_width -= i;
	if (!spec->to_left)
		while (fill_width-- > 0)
			i += ft_print_char(fill, 1);
	if (!spec->to_left)
		while (spec->prec-- > 0)
			i += ft_print_char('0', 1);
	i += spec->prec > 0 ? ft_print_char('0', spec->prec) : 0;
	i += (!num && (!spec->dot && spec->prec)) ? ft_print_char('0', 1) : 0;
	num ? ft_to_base(num, 16, spec->format == 'X', &i) : 0;
	i += fill_width > 0 ? ft_print_char(' ', fill_width) : 0;
	return (i);
}
