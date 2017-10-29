#include "includes/libft.h"

int	main(void)
{
	int x;
	int ret;
	char *ptr = "|what is a sup dog|";

	ret = ft_printf("hi %s rob?\n", ptr);
	ft_putnbr(ret);
	return (0);
}