/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:46 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:32:50 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_int(t_spec *spec, va_list ap)
{
	int		number;
	int		fill_width;
	int		strlen;
	int		i;

	i = 0;
	number = va_arg(ap, int);
	strlen = ft_digit_len(number);
	if (number < 0)
		strlen++;
	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
	spec->width += spec->show_sign;
	fill_width = spec->width - strlen - spec->show_sign;
	spec->prec -= strlen;
	if (spec->prec > 0)
		fill_width -= spec->prec + spec->show_sign;
	if (!spec->to_left)
		i += ft_print_char(' ', fill_width);
	i += print_sign(number, spec);
	while (spec->prec-- > 0)
		i += ft_print_char('0', 1);
	i += ft_print_num(number);
	if (spec->to_left)
		i += ft_print_char(' ', fill_width);
	return (i);
}
