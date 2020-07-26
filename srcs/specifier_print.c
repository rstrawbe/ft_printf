/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:36:09 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 19:36:20 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	specifier_print(t_spec *spec)
{
	printf("spec->spec_len: %d\n", spec->spec_len);
	printf("spec->error: %c\n", spec->error);
	printf("spec->left: %c\n", spec->to_left);
	printf("spec->show_sign: %d\n", spec->show_sign);
	printf("spec->first_space: %c\n", spec->first_space);
	printf("spec->fill_zero: %c\n", spec->fill_zero);
	printf("spec->width: %d\n", spec->width);
	printf("spec->prec: %d\n", spec->prec);
	printf("spec->format: %c\n", spec->format);
}
