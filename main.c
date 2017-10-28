#include "includes/libft.h"

int	main(void)
{
	int x;
	char *ptr;

	x = 0;
	ptr = ft_itoa(x);
	ft_putstr(ptr);
	return (0);
}
