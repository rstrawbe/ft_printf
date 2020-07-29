/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:33:22 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:33:27 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_argument(t_spec *spec, va_list ap)
{
	int		i;

	i = 0;
	i += (spec->format == 'c') ? render_arg_char(spec, ap) : 0;
	i += (spec->format == '%') ? render_arg_percent(spec) : 0;
	i += (spec->format == 's') ? render_arg_string(spec, ap) : 0;
	i += (spec->format == 'd') ? render_arg_int(spec, ap) : 0;
	i += (spec->format == 'i') ? render_arg_int(spec, ap) : 0;
	i += (spec->format == 'u') ? render_arg_uint(spec, ap) : 0;
	i += (spec->format == 'p') ? render_arg_addr(spec, ap) : 0;
	i += (spec->format == 'x') ? render_arg_base16(spec, ap) : 0;
	i += (spec->format == 'X') ? render_arg_base16(spec, ap) : 0;
	return (i);
}
