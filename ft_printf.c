#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int		ft_print_str(char *str, int	pricision)
{
	int		i;

	i = 0;
	if (*str)
		while (*str && pricision--)
			i += write(1, str++, 1);
	return (i);
}

int		ft_print_char(char s, int count)
{
	int		i;

	i = 0;
	if (count < 0)
		return (0);
	while (count)
	{
		i += write(1, &s, 1);
		count--;
	}
	return (i);
}

void	specifier_print(t_spec *spec)
{
	printf("spec->specLen: %d\n", spec->specLen);
	printf("spec->error: %c\n", spec->error);
	printf("spec->left: %c\n", spec->to_left);
	printf("spec->show_sign: %d\n", spec->show_sign);
	printf("spec->first_space: %c\n", spec->first_space);
	printf("spec->fill_zero: %c\n", spec->fill_zero);
	printf("spec->width: %d\n", spec->width);
	printf("spec->precision: %d\n", spec->precision);
	printf("spec->format: %c\n", spec->format);
}

void	specifier_clear(t_spec *spec)
{
	spec->error = 0;
	spec->specLen = 0;
	spec->to_left = 0;
	spec->show_sign = 0;
	spec->first_space = 0;
	spec->fill_zero = 0;
	spec->width = 0;
	spec->dot = 0;
	spec->precision = 0;
	spec->format = 0;
}

void	set_fields(t_spec *s, char *p, va_list ap)
{
	s->precision = (*p == '.' && s->dot) ? 0 : s->precision;
	s->dot = (*p == '.') ? '1' : s->dot;
	s->to_left = (*p == '-') ? '1' : s->to_left;
	s->show_sign = (*p == '+') ? 1 : s->show_sign;
	s->first_space = (*p == ' ') ? '1' : s->first_space;
	s->fill_zero = (*p == '0' && !s->width && !s->precision) ? '1' : s->fill_zero;
	s->width = (*p == '*' && !s->dot) ? va_arg(ap, int) : s->width;
	s->precision = (*p == '*' && s->dot) ? va_arg(ap, int) : s->precision;
}

int		is_digit(char *str)
{
	return (*str > 47 && *str < 58);
}

int		isFlag(char *str)
{
	char	*flags;

	flags = FT_PRINTF_FLAGS;
	while (*flags)
		if (*flags++ == *str)
			return (1);
	return (0);
}

char	*get_digit_while_int(char *str, int *dest, int *specLen)
{
	int		res;
	int		count;

	res = 0;
	if (*str == '0')
	{
		*specLen += 1;
		return (str + 1);
	}
	while (is_digit(str))
	{
		res = (res * 10) + (*str++ - 48);
		*specLen += 1;
	}
	*dest = res;
	return (str);
}

int		render_arg_char(t_spec *spec, va_list ap)
{
	char	ch;
	char	fill;
	int		fill_width;

	if (!(ch = va_arg(ap, int)))
		ch = 0;
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - 1;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_str(&ch, 1));
	else
		return (ft_print_str(&ch, 1) + ft_print_char(fill, fill_width));
}

int		render_arg_percent(t_spec *spec, va_list ap)
{
	char	ch;
	char	fill;
	int		fill_width;

	ch = '%';
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - 1;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_str(&ch, 1));
	else
		return (ft_print_str(&ch, 1) + ft_print_char(fill, fill_width));
}

int		ft_strlen(char	*str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (*str && ++i)
		str++;
	return (i);
}

int		rendera_arg_string(t_spec *spec, va_list ap)
{
	char	*str;
	char	fill;
	int		fill_width;
	int		strlen;
	int		max_str;

	if (!(str = va_arg(ap, char *)))
		str = FT_PRINTF_NULL_STR;
	strlen = ft_strlen(str);
	max_str = spec->precision < strlen ? spec->precision : strlen;
	fill = (spec->fill_zero && !spec->to_left) ? '0' : ' ';
	fill_width = spec->width - max_str;
	if (!spec->to_left)
		return (ft_print_char(fill, fill_width) + ft_print_str(str, max_str));
	else
		return (ft_print_str(str, max_str) + ft_print_char(fill, fill_width));
}

int		ft_digit_len(int num)
{
	int		count;

	count = 0;
	while (++count && num / 10)
		num /= 10;
	// if (num < 0)
	// 	count++;
	return (count);
}

int		print_sign(int	num, t_spec *spec)
{
	int i;
	char sign;

	i = 0;
	sign = '+';
	if (spec->show_sign && num >= 0 && ++i)
		write(1, &sign, 1);
	sign = '-';
	if (num < 0 && ++i)
		write(1, &sign, 1);
	return (i);
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb == -2147483648)
	{
		n = '2';
		write(1, &n, 1);
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putnbr(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		n = (nb % 10) + '0';
		write(1, &n, 1);
	}
}

int		ft_print_num(int num)
{
	ft_putnbr(num);
	return (0);
}

int		render_arg_int(t_spec *spec, va_list ap)
{
	int		number;
	char	fill;
	int		fill_width;
	int		strlen;
	int		max_str;
	int		i;

	i = 0;
	number = va_arg(ap, int);
	strlen = ft_digit_len(number);
	//max_str = spec->precision < strlen ? spec->precision : strlen;
	max_str = strlen;
	spec->width = spec->width > spec->precision ? spec->width + spec->show_sign : spec->precision + spec->show_sign ;
	//spec->to_left = spec->precision < spec->width ? spec->to_left : 0;
	fill = (spec->precision && !spec->to_left) ? '0' : ' ';

	if (number < 0)
		max_str++;

	fill_width = spec->width - max_str - spec->show_sign;

	//spec->precision = spec->precision < spec->width ? spec->precision - strlen : fill_width;

	i += print_sign(number, spec);

//	while (fill_width && spec->precision + 1)
	while ( (spec->precision--) > 0)
	{
		
		i += ft_print_char('7', 1);
		fill_width--;
		spec->width--;
		spec->precision = spec->precision - 1;
	}
	if (!spec->to_left)
		return (i + ft_print_char(fill, fill_width) + ft_print_num(number) + strlen);
	else
		return (i + ft_print_num(number) + ft_print_char(fill, fill_width) + strlen);
}

int		render_argument(t_spec *spec, va_list ap)
{
	int		i;

	i = 0;
	i += (spec->format == 'c') ? render_arg_char(spec, ap) : 0;
	i += (spec->format == '%') ? render_arg_percent(spec, ap) : 0;
	i += (spec->format == 's') ? rendera_arg_string(spec, ap) : 0;
	i += (spec->format == 'd') ? render_arg_int(spec, ap) : 0;
	return (i);
}

int		specifier_init(t_spec *spec, char *str, va_list ap)
{
	char	*conv;

	specifier_clear(spec);
	while (*str && (isFlag(str) || is_digit(str)))
	{
		set_fields(spec, str, ap);
		if (is_digit(str) && !spec->dot && !spec->width)
			str = get_digit_while_int(str, &spec->width, &spec->specLen);
		else if (is_digit(str) && spec->dot && !spec->precision)
			str = get_digit_while_int(str, &spec->precision, &spec->specLen);
		else
		{
			spec->specLen++;
			str++;
		}
	}
	spec->specLen++;
	conv = FT_PRINTF_CONV;
	while (*conv)
		spec->format = (*conv++ == *str) ? *(conv - 1) : spec->format;
	return (spec->format ? render_argument(spec, ap) : 0);
}

int		ft_printf(const char *str, ...)
{
	t_spec		spec;
	va_list		ap;
	int			i;

	i = 0;
	if (!str && ft_print_str("(nrull)", 7))
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += specifier_init(&spec, (char *)str + 1, ap);
			str += spec.format ? spec.specLen : 0;
		}
		else
			i += write(1, str, 1);
		str++;
	}
	specifier_print(&spec);
	va_end(ap);
	return (i);
}

int		main(void)
{
	int		n = 50;
	int		i;
	int		cnt;
	// printf("|%7d|\n", 212121);
	// printf("|%-7d|\n", 212121);
	// printf("|%7s|\n", "str");

	// cnt = 0;
	// i = ft_digit_len(-558);
	// printf("%d\n", i);

	i = printf("%+6d", n);
	printf("\n%d\n", i);

	return (0);
}
