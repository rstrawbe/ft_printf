/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 22:14:41 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/29 22:14:53 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_addr(t_spec *spec, va_list ap)
{
	unsigned long long	number;
    int             strlen;
	int				fill_width;
	int				i;

	i = 0;
    strlen = 2;
	number = va_arg(ap, unsigned long long);
    to_base_cnt(number, 16, &strlen);
    fill_width = spec->width - strlen;
    if (!spec->to_left)
        while (fill_width-- > 0)
            i += ft_print_char(' ', 1);
    i += ft_print_char('0', 1) + ft_print_char('x', 1);
    ft_to_base(number, 16, 0, &i);
    if (spec->to_left)
        while (fill_width-- > 0)
            i += ft_print_char(' ', 1);
	return (i);
}
