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
	unsigned long long	number;
	int					strlen;
	int					fill_width;
	int					upper;
	int					i;

	i = 0;
	strlen = 0;
	upper = spec->format == 'X' ? 1 : 0;
	number = va_arg(ap, unsigned long long);
	to_base_cnt(number, 16, &strlen);
	strlen = number == 0 ? 1 : strlen;
	fill_width = spec->width - strlen;
	spec->prec -= strlen;
	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
	if (!spec->to_left)
		while (fill_width-- > 0)
			i += ft_print_char(' ', 1);
	if (!spec->to_left)
		while (spec->prec-- > 0)
			i += ft_print_char('0', 1);
	i += spec->prec > 0 ? ft_print_char('0', spec->prec) : 0;
	ft_to_base(number, 16, upper, &i);
	i += fill_width > 0 ? ft_print_char(' ', fill_width) : 0;
	return (i);
}
