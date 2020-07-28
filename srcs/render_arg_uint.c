/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:09:03 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/28 22:09:10 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_uint(t_spec *spec, va_list ap)
{
	unsigned int		number;
	int		fill_width;
	int		strlen;
	int		i;

	i = 0;
	number = va_arg(ap, unsigned int);
	strlen = ft_digit_len(number);
	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
	fill_width = spec->width - strlen;
	spec->prec -= strlen;
	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
	i = !spec->to_left ? ft_print_char(' ', fill_width) : i;
	while (spec->prec-- > 0)
		i += ft_print_char('0', 1);
	i += ft_putnbr(number);
	i = (spec->to_left) ? i + ft_print_char(' ', fill_width) : i;
	return (i + strlen);
}
