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
void	specifier_print(t_spec *spec);

int		ft_printf(const char *, ...);
int		specifier_init(t_spec *spec, char *str, va_list ap);
void	specifier_clear(t_spec *spec);

int		is_flag(char *str);
int		is_digit(char *str);
char	*get_digit_while_int(char *str, int *dest, int *specLen);
void	set_fields(t_spec *s, char *p, va_list ap);

int		render_argument(t_spec *spec, va_list ap);
int		render_arg_percent(t_spec *spec, va_list ap);
int		render_arg_char(t_spec *spec, va_list ap);
int		render_arg_string(t_spec *spec, va_list ap);
int		render_arg_int(t_spec *spec, va_list ap);

int		print_sign(int	num, t_spec *spec);
int		ft_digit_len(int num);

int		ft_strlen(char	*str);
int		ft_print_str(char *str, int	pricision);
void	ft_putnbr(int nb);


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

#endif