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

static int	ft_putlong(long long nb)
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

static int	ft_nbr(long long nb)
{
	char	n;

	if (nb < 0)
		ft_nbr(nb * (-1));
	else
	{
		if (nb >= 10)
			ft_nbr(nb / 10);
		n = (nb % 10) + '0';
		write(1, &n, 1);
	}
	return (0);
}

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

// int		render_arg_int(t_spec *spec, va_list ap)
// {
// 	int		number;
// 	int		fill_width;
// 	int		strlen;
// 	int		i;
// 	char	fill;

// 	i = 0;
// 	number = va_arg(ap, int);
// 	strlen = !number && !spec->prec ? 0 : ft_digit_len(number);
// 	spec->show_sign = number < 0 ? 1 : spec->show_sign;
// 	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
// 	fill_width = spec->width - strlen - spec->show_sign;
// 	spec->prec -= strlen;
// 	fill_width = spec->prec > 0 ? fill_width - spec->prec : fill_width;
// 	//fill = spec->fill_zero && !spec->to_left ? '0' : ' ';
// 	fill = (spec->prec > 0 || spec->fill_zero) && !spec->to_left ? '0' : ' ';

// 	if (strlen < spec->width)
// 		i += print_sign(number, spec);
// 	if (!spec->to_left)
// 	{
// 		while (fill_width-- > 0)
// 			i += ft_print_char(fill, 1);

// 		while (spec->prec > strlen && spec->prec-- > 0)
// 			i += ft_print_char('0', 1);

// 	}
// 	if (strlen >= spec->width)
// 		i += print_sign(number, spec);
// 	i += spec->prec > 0 ? ft_print_char(fill, spec->prec) : 0;
// 	i += !number && !strlen ? 0 : ft_putlong(number);
// 	i += fill_width > 0 ? ft_print_char(fill, fill_width) : 0;

// 	return (i + strlen);
// }
