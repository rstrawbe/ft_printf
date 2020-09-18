/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:33:10 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:31:12 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		render_arg_string(t_spec *spec, va_list ap)
{
	char	*str;
	char	fill;
	int		fill_width;
	int		strlen;
	int		max_str;

	if (!(str = va_arg(ap, char *)))
		str = FT_PRINTF_NULL_STR;
	strlen = ft_strlen(str);
	max_str = spec->prec > 0 && spec->prec < strlen ? spec->prec : strlen;
	max_str = spec->dot && spec->prec == 0 ? 0 : max_str;
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - max_str;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_str(str, max_str));
	else
		return (ft_print_str(str, max_str) + ft_print_char(fill, fill_width));
}
