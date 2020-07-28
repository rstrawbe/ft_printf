#include <stdio.h>
#include "srcs/ft_printf.h"

int		main(void)
{
	int		n = 50;
	int		i;
	// printf("|%7d|\n", 212121);
	// printf("|%-7d|\n", 212121);
	// printf("|%7s|\n", "str");

	// cnt = 0;

    i = printf("|%-+10.45d|\n", -0572);
	printf("\n%d\n", i);

	i = ft_printf("|%-+10.45d|\n", -0572);
	printf("\n%d\n", i);


	return (0);
}