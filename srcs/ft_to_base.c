/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:20:37 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/30 02:17:57 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_base(unsigned long long n, int b, int u, int *i)
{
	if (n == 0 && !*i)
	{
		*i += 1;
		if (u)
			write(1, &BASE_16_UPPER[n % b], 1);
		else
			write(1, &BASE_16_LOWER[n % b], 1);
	}
	if (n)
	{
		*i += 1;
		ft_to_base(n / b, b, u, i);
		if (u)
			write(1, &BASE_16_UPPER[n % b], 1);
		else
			write(1, &BASE_16_LOWER[n % b], 1);
	}
}
