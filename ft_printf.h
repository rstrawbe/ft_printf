/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 18:35:52 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/07/26 03:59:48 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *, ...);

typedef struct		s_spec
{
	char			error;
	int				specLen;
	char			to_left;
	int				show_sign;
	char			first_space;
	char			fill_zero;
	int				width;
	char			dot;
	int				precision;
	char			format;
}					t_spec;
#define FT_PRINTF_CONV "cspdiuxX%"
#define FT_PRINTF_FLAGS "-+0.*"
#define FT_PRINTF_NULL_STR "(null)"
