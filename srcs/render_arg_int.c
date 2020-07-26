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
	char	fill;
	int		fill_width;
	int		strlen;
	int		max_str;
	int		i;

	i = 0;
	number = va_arg(ap, int);
	strlen = ft_digit_len(number);
	//max_str = spec->prec < strlen ? spec->prec : strlen;
	max_str = strlen;
	spec->width = spec->width > spec->prec ? spec->width + spec->show_sign : spec->prec + spec->show_sign ;
	//spec->to_left = spec->prec < spec->width ? spec->to_left : 0;
	fill = (spec->prec && !spec->to_left) ? '0' : ' ';

	if (number < 0)
		max_str++;

	fill_width = spec->width - max_str - spec->show_sign;

	//spec->prec = spec->prec < spec->width ? spec->prec - strlen : fill_width;

	i += print_sign(number, spec);

//	while (fill_width && spec->prec + 1)
	while ( (spec->prec--) > 0)
	{
		
		i += ft_print_char('7', 1);
		fill_width--;
		spec->width--;
		spec->prec = spec->prec - 1;
	}
	if (!spec->to_left)
		return (i + ft_print_char(fill, fill_width) + ft_print_num(number) + strlen);
	else
		return (i + ft_print_num(number) + ft_print_char(fill, fill_width) + strlen);
}
