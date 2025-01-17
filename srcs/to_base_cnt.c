/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_base_cnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 01:44:08 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:33:11 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		to_base_cnt(unsigned long long nb, int base, int *i)
{
	if (nb == 0 && !*i)
		*i += 1;
	if (nb)
	{
		*i += 1;
		to_base_cnt(nb / base, base, i);
	}
}
