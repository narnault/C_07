#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max) {

	int	i;

    i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (i);
	}
	if (!(*range = malloc(sizeof(int) * (max - min))))
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
	free (*range);
}

int		main(void) {

	int		*range;
	int     i = 0;

	printf("return : %d\n", ft_ultimate_range(&range, -5, 50));
	while (i < ft_ultimate_range(&range, -55, 50))
	{
	printf("%i\n", range[i]);
		i++;
	}
	return (0);
}
