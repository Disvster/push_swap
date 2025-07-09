#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int	main(void)
{
	char	*lol;
	int		*p;
	int		a;
	int		*p_a;

	
	a = 3;


	p_a = &a;

	printf("%d\n", &p_a);
	printf("%d\n", p_a);
	printf("%d\n", &a);
	return (0);
}
