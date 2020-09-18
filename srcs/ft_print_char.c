/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:30:50 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/08/07 23:28:02 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_char(char s, int count)
{
	int		i;

	i = 0;
	if (count < 0)
		return (0);
	while (count > 0)
	{
		i += write(1, &s, 1);
		count--;
	}
	return (i);
}
