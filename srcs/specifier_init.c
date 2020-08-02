/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:35:28 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:35:35 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		specifier_init(t_spec *spec, char *str, va_list ap)
{
	char	*conv;

	specifier_clear(spec);
	while (*str && (is_flag(str) || is_digit(str)))
	{
		set_fields(spec, str, ap);
		if (is_digit(str) && !spec->dot && !spec->width)
			str = get_digit_while_int(str, &spec->width, spec);
		else if (is_digit(str) && spec->dot && !spec->prec)
			str = get_digit_while_int(str, &spec->prec, spec);
		else
		{
			spec->spec_len++;
			str++;
		}
	}
	spec->spec_len++;
	conv = FT_PRINTF_CONV;
	while (*conv)
		spec->format = (*conv++ == *str) ? *(conv - 1) : spec->format;
	return (spec->format ? render_argument(spec, ap) : 0);
}
