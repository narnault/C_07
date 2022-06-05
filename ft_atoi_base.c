#include <stdio.h>
#include <stdlib.h>

int		carac(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int		verif(char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| carac(base[i], base + i + 1) >= 0
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
	return ((i < 2) ? 0 : i);
}

int		ft_atoi_base(char *str, char *base, int size)
{
	int i;
	int j;
	int n;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	n = 0;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			n = 1 - n;
	j = 0;
	while ((i = carac(*str++, base)) >= 0)
		j = j * size + i;
	if (n)
		j *= -1;
	return (j);
}

int		what_long(unsigned int i, unsigned int lng)
{
	if (i < lng)
		return (1);
	return (1 + what_long(i / lng, lng));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*dest;
	unsigned int	lng;
	int				i;
	int				j;
	int				k;

	k = verif(base_from);
	if (!(k && (j = verif(base_to))))
		return (NULL);
	k = ft_atoi_base(nbr, base_from, k);
	lng = (k < 0) ? -k : k;
	i = what_long(lng, j) + ((k < 0) ? 1 : 0);
	if (!(dest = malloc((i + 1) * sizeof(char))))
		return (NULL);
	dest[i] = '\0';
	while (i--)
	{
		dest[i] = base_to[lng % j];
		lng /= j;
	}
	if (k < 0)
		dest[0] = '-';
	return (dest);
}

int main()
{
    char *nbr = "0101101";
    char *from = "01";
    char *to = "0123456789ABCDEF";
    printf("%s", ft_convert_base(nbr, from, to));
}
