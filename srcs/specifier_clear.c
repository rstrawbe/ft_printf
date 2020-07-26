/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:34:03 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:34:17 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_clear(t_spec *spec)
{
	spec->error = 0;
	spec->spec_len = 0;
	spec->to_left = 0;
	spec->show_sign = 0;
	spec->first_space = 0;
	spec->fill_zero = 0;
	spec->width = 0;
	spec->dot = 0;
	spec->prec = 0;
	spec->format = 0;
}
