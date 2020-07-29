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
	strlen = !number && !spec->prec ? 0 : ft_digit_len(number);
	spec->show_sign = number < 0 ? 1 : spec->show_sign;
	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
	fill_width = spec->width - strlen - spec->show_sign;
	spec->prec -= strlen;
	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
	i = !spec->to_left ? ft_print_char(' ', fill_width) : i;
	i += print_sign(number, spec);
	while (spec->prec-- > 0)
		i += ft_print_char('0', 1);
	i += !number && !strlen ? 0 : ft_putnbr(number);
	i = (spec->to_left) ? i + ft_print_char(' ', fill_width) : i;
	return (i + strlen);
}
