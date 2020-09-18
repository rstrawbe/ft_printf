/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:31:02 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:28:14 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			ft_print_str(char *str, int pricision)
{
	int		i;

	i = 0;
	if (*str)
		while (*str && pricision--)
			i += write(1, str++, 1);
	return (i);
}
