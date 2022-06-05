#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str) {

	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src) {

	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j]) {

		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i + j] = 0;
	return (dest);
}

int		what_long(char **strs, int size, char *sep) {

	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size) {

		j += ft_strlen(strs[i]);
		i++;
	}
	j += (size) * ft_strlen(sep) + 1;
	return (j);
}

char	*ft_strjoin(int size, char **strs, char *sep) {

	int		i;
	char	*src;

	i = 0;
	if (size == 0) {

		src = malloc(sizeof(char));
		*src = 0;
		return (src);
	}
	if (!(src = malloc(sizeof(char) * what_long(strs, size, sep))))
		return (NULL);
	*src = 0;
	while (i < size) {

		ft_strcat(src, strs[i]);
		if (i < size)
			ft_strcat(src, sep);
		i++;
	}
	return (src);
	free (src);
}

int    main(void) {

    char    *tab[4];
    tab[0] = " ";
    tab[1] = " ";
    tab[2] = " ";
    tab[3] = " ";
    printf("%s", ft_strjoin(4, tab, "Pasquale"));
    return (0);
}
