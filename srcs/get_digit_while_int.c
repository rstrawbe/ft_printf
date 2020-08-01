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

char	*get_digit_while_int(char *str, int *dest, int *spec_len)
{
	int		res;

	res = 0;
	*dest = 0;
	if (*str == '0')
	{
		*spec_len += 1;
		return (str + 1);
	}
	while (is_digit(str))
	{
		res = (res * 10) + (*str++ - 48);
		*spec_len += 1;
	}
	*dest = res;
	return (str);
}
