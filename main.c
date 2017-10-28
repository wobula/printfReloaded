#include "includes/libft.h"

int	main(void)
{
	int x;
	char *ptr = "what is a sup dog?";
	char **ptr2;

	ptr2 = ft_strsplit(ptr, ' ');
	x = -1;
	while (ptr2[++x])
	{
		ft_putstr(ptr2[x]);
		ft_putchar('\n');
	}
	return (0);
}
