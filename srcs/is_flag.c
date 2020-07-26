/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:32:15 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:32:17 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char *str)
{
	char	*flags;

	flags = FT_PRINTF_FLAGS;
	while (*flags)
		if (*flags++ == *str)
			return (1);
	return (0);
}
