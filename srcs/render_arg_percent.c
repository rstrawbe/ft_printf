/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arg_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:58 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:33:01 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		render_arg_percent(t_spec *spec)
{
	char	ch;
	char	fill;
	int		fill_width;

	ch = '%';
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - 1;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_str(&ch, 1));
	else
		return (ft_print_str(&ch, 1) + ft_print_char(fill, fill_width));
}
