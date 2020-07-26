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
	return (i);
}
