#include "includes/libft.h"

int	main(void)
{
	char *buff1 = "robin";
	char *buff2 = "schramm";
	char *ptr;

	ptr = NULL;
	ptr = ft_strjoin(buff1, buff2);
	ft_putstr(ptr);
	return (0);
}
