/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:31:16 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:31:18 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(unsigned long long nb)
{
	char	n;

	if (nb < 0)
		ft_putnbr(nb * (-1));
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		n = (nb % 10) + '0';
		write(1, &n, 1);
	}
	return (0);
}
