/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:25 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:51:15 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_sign(int num, t_spec *spec)
{
	int		i;
	char	sign;

	i = 0;
	sign = '+';
	if (spec->show_sign && num >= 0 && ++i)
		write(1, &sign, 1);
	sign = '-';
	if (num < 0 && ++i)
		write(1, &sign, 1);
	return (i);
}
