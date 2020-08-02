/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:14:41 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/30 02:28:54 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						render_arg_addr(t_spec *spec, va_list ap)
{
	unsigned long long	number;
	int					strlen;
	int					fill_width;
	char				fill;
	int					i;
	int					prefix;

	i = 0;
	strlen = 0;
	prefix = 2;
	number = va_arg(ap, unsigned long long);
	if (!spec->width)
		spec->width = spec->prec;
	//spec->width = spec->width > spec->prec ? spec->width : spec->prec;
	to_base_cnt(number, 16, &strlen);

	if (!number)
		strlen = prefix;
	
	fill_width = spec->width - strlen - prefix;
	
	if (spec->prec > strlen)
		spec->prec -= strlen;
	else
	{
			spec->prec = 0;
	}
	if (!number && spec->prec > 0)
		fill_width--;
	
	if (!number && spec->dot && spec->prec)
		spec->prec++;
	
	// if (spec->prec)
	// 	fill_width -= spec->prec;

	fill = spec->prec ? '0' : ' ';
	if (!spec->to_left)
		while (fill_width-- > 0)
			i += ft_print_char(' ', 1);
	i += ft_print_char('0', 1) + ft_print_char('x', 1);
	i += ft_print_char('0', spec->prec);
	ft_to_base(number, 16, 0, &i);
	if (spec->to_left)
		while (fill_width-- > 0)
			i += ft_print_char(' ', 1);
	return (i);
}


// unsigned long long	number;
// 	int					strlen;
// 	int					fill_width;
// 	char				fill;
// 	int					i;

// 	i = 0;
// 	strlen = 2;
// 	number = va_arg(ap, unsigned long long);
// 	spec->width = spec->width > spec->prec ? spec->width : spec->prec;
// 	to_base_cnt(number, 16, &strlen);
// 	fill = spec->prec ? '0' : ' ';
// 	fill_width = spec->width - strlen;
// 	if (!spec->to_left)
// 		while (fill_width-- > 0)
// 			i += ft_print_char(' ', 1);
// 	i += ft_print_char('0', 1) + ft_print_char('x', 1);
// 	ft_to_base(number, 16, 0, &i);
// 	if (spec->to_left)
// 		while (fill_width-- > 0)
// 			i += ft_print_char(' ', 1);
// 	return (i);





	// unsigned long long	number;
	// int					strlen;
	// int					fill_width;
	// char				fill;
	// int					i;

	// int prec;
	// int width;
	// int zeros;

	// i = 0;
	// prec = spec->prec;
	// width = spec->width;
	// number = va_arg(ap, unsigned long long);
	// width = width > prec ? width : spec->prec;


	// strlen += number == 0 && !spec->dot ? 1 : 0;
	
	// to_base_cnt(number, 16, &strlen);

	// strlen = spec->dot && !prec ? 2 : strlen;
	// fill = prec ? '0' : ' ';
	// fill_width = width;

	// fill_width -= prec > strlen ? prec : strlen;

	// prec = spec->prec;
	// if (prec > strlen)
	// 	prec -= strlen;
	
	// prec += !number ? 1 : 0;

	// fill_width -= number == 0 ? 1 : 0;
	// prec = number == 0 && width ? 1 : prec;
	// if (!spec->to_left)
	// 	while (fill_width-- > 0)
	// 		i += ft_print_char(' ', 1);
	// i += ft_print_char('0', 1) + ft_print_char('x', 1);
	// i += ft_print_char('0', prec);

	// //i += !number && spec->width && !spec->prec ? ft_print_char('0', 1) : 0;
	// //i += !number && (spec->width || spec->prec) ? ft_print_char('0', 1) : 0;
	// ft_to_base(number, 16, 0, &i);
	// if (spec->to_left)
	// 	while (fill_width-- > 0)
	// 		i += ft_print_char(' ', 1);
	// return (i);