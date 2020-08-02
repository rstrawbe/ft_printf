/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:09:03 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/28 23:09:44 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_uint(t_spec *spec, va_list ap)
{
	unsigned int	number;
	int				fill_width;
	int				strlen;
	int				i;
	char			fill;

	i = 0;
	number = va_arg(ap, unsigned int);
	strlen = !number && !spec->prec ? 0 : ft_digit_len(number);
	strlen = number == 0 && !spec->dot ? 1 : strlen;
	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
	fill_width = spec->width - strlen;
	spec->prec -= strlen;
	fill = ' ';
	if (spec->fill_zero && !spec->dot)
		fill = '0';
	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
	i = !spec->to_left ? ft_print_char(fill, fill_width) : i;
	while (spec->prec-- > 0)
		i += ft_print_char('0', 1);
	i += !number && !strlen ? 0 : ft_putnbr(number);
	i = (spec->to_left) ? i + ft_print_char(fill, fill_width) : i;
	return (i + strlen);
}
