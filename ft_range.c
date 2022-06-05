#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
        write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

void	ft_put_int_tab(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr(tab[i]);
		ft_putchar(' ');
		i++;
	}
}

int	*ft_range(int min, int max)
{
        int     i;
        int  *tab;

        i = 0;
        if (min >= max)
                return (NULL);
        tab = malloc(sizeof(int) * (max - 1));
        while (min < max)
        {
                tab[i] = min;
                i++;
                min++;
        }
	tab[i] = '\0';
        return (tab);
        free (tab);
}

int main()
{
	int min = 15;
	int max = 28;
	ft_put_int_tab(ft_range(min, max));
	return (0);
}
