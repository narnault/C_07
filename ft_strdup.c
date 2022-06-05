#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int	i;
	char	*p;

	i = 0;
	while (src[i])
		i++;
	p = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	return (p);
	free (p);
}

int main()
{
    char *src = "salut cest cool";
    printf("%s", ft_strdup(src));
    return (0);
}
