/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:55:21 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:34:16 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_spec		spec;
	va_list		ap;
	int			i;

	i = 0;
	if (!str && ft_print_str(FT_PRINTF_NULL_STR, 7))
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += specifier_init(&spec, (char *)str + 1, ap);
			str += spec.format ? spec.spec_len : 0;
		}
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (i);
}
