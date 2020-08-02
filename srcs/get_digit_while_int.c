/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_digit_while_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:31:41 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:31:43 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_digit_while_int(char *str, int *dest, t_spec *spec)
{
	int		res;

	res = 0;
	*dest = 0;
	// if (spec->dot)
	// 	spec->prec_init = '1';
	// else if (is_digit(str + 1))
	// 	spec->width_init = '1';

	if (*str == '0')
	{
		spec->spec_len += 1;
		return (str + 1);
	}
	while (is_digit(str))
	{
		res = (res * 10) + (*str++ - 48);
		spec->spec_len += 1;
	}
	*dest = res;
	return (str);
}
