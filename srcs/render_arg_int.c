/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:46 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:30:46 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_putlong(long long nb)
{
	char	n;

	if (nb < 0)
		ft_putlong(nb * (-1));
	else
	{
		if (nb >= 10)
			ft_putlong(nb / 10);
		n = (nb % 10) + '0';
		write(1, &n, 1);
	}
	return (0);
}

static int		get_fill_width(t_spec *spec, int strlen)
{
	int			width;

	width = spec->width - spec->show_sign;
	width -= spec->prec > strlen ? spec->prec : strlen;
	return (width);
}

static char		get_fill(t_spec *spec, int strlen, int num)
{
	char		fill;

	fill = spec->to_left || !spec->fill_zero ? ' ' : '0';
	fill = spec->fill_zero && spec->prec > strlen ? ' ' : fill;
	fill = spec->fill_zero && spec->prec > 0 ? ' ' : fill;
	fill = num == 0 && spec->prec_init && !spec->prec ? ' ' : fill;
	fill = spec->fill_zero && spec->prec_init && !spec->prec ? ' ' : fill;
	spec->prec -= strlen;
	return (fill);
}

int				render_arg_int(t_spec *spec, va_list ap)
{
	int			number;
	int			fill_width;
	int			strlen;
	int			i;
	char		fill;

	i = 0;
	number = va_arg(ap, int);
	strlen = !number && !spec->prec ? 0 : ft_digit_len(number);
	strlen = number == 0 && !spec->dot ? 1 : strlen;
	spec->show_sign = number < 0 ? 1 : spec->show_sign;
	fill_width = get_fill_width(spec, strlen);
	fill = get_fill(spec, strlen, number);
	if (spec->to_left)
	{
		i += print_sign(number, spec) + ft_print_char('0', spec->prec);
		i += !number && !strlen ? 0 : ft_putlong(number);
		return (i + strlen + ft_print_char(fill, fill_width));
	}
	i += (fill == '0') ? print_sign(number, spec) : 0;
	i += ft_print_char(fill, fill_width);
	i += (fill == ' ') ? print_sign(number, spec) : 0;
	i += ft_print_char('0', spec->prec);
	i += !number && !strlen ? 0 : ft_putlong(number);
	return (i + strlen);
}
