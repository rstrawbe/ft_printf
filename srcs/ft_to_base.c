/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:20:37 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/30 01:21:12 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_base(unsigned long long nb, int base, int upper, int *i)
{
	if (nb)
	{
        *i += 1;
		ft_to_base(nb / base, base, upper, i);
		if (upper)
			write(1, &BASE_16_UPPER[nb % base], 1);
		else
			write(1, &BASE_16_LOWER[nb % base], 1);
	}
}

