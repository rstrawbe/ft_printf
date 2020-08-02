/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:35 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:32:37 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_char(t_spec *spec, va_list ap)
{
	char	ch;
	char	fill;
	int		fill_width;

	if (!(ch = va_arg(ap, int)))
		ch = '\0';
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - 1;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_char(ch, 1));
	else
		return (ft_print_char(ch, 1) + ft_print_char(fill, fill_width));
}
