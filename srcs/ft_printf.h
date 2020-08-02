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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct		s_spec
{
	char			error;
	char			width_init;
	char			prec_init;
	int				spec_len;
	char			to_left;
	int				show_sign;
	char			first_space;
	char			fill_zero;
	int				width;
	char			dot;
	int				prec;
	char			format;
}					t_spec;

void				specifier_print(t_spec *spec);

int					ft_printf(const char *str, ...);
int					specifier_init(t_spec *spec, char *str, va_list ap);
void				specifier_clear(t_spec *spec);

int					is_flag(char *str);
int					is_digit(char *str);
char				*get_digit_while_int(char *str, int *dest, t_spec *spec);
void				set_fields(t_spec *s, char *p, va_list ap);

int					render_argument(t_spec *spec, va_list ap);
int					render_arg_percent(t_spec *spec);
int					render_arg_char(t_spec *spec, va_list ap);
int					render_arg_string(t_spec *spec, va_list ap);
int					render_arg_int(t_spec *spec, va_list ap);
int					render_arg_uint(t_spec *spec, va_list ap);
int					render_arg_addr(t_spec *spec, va_list ap);
int					render_arg_base16(t_spec *spec, va_list ap);

int					print_sign(int	num, t_spec *spec);
int					ft_digit_len(long long num);

int					ft_strlen(char	*str);
int					ft_print_char(char s, int count);
int					ft_print_str(char *str, int	pricision);
int					ft_putnbr(unsigned long long nb);
void				ft_to_base(unsigned long long n, int b, int u, int *i);
void				to_base_cnt(unsigned long long nb, int base, int *i);

# define FT_PRINTF_CONV "cspdiuxX%"
# define FT_PRINTF_FLAGS "-+0.*"
# define FT_PRINTF_NULL_STR "(null)"

# define BASE_16_UPPER "0123456789ABCDEF"
# define BASE_16_LOWER "0123456789abcdef"

#endif
