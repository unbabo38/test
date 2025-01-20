#include <unistd.h>
#include <stdio.h>

int	numb(char *str, int max, int n, char *base)
{
	int	i;
	int ans;

	i = 0;
	ans = 0;
	while (i < max)
	{
		ans = n * ans + str[i] - '0';
		i++;
	}

	return (ans);
}

int		basenumber(char *str, char *base, int n)
{
	int	i;
	int	pm;
	int	ans;

	pm = 1;
	i = 0;
	ans = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			pm = -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			break ;
		}
		i++;
	}

	if(pm == -1)
		write(1, "-", 1);
	return (numb(str,i,n,base));
}

void	shokika(int ascii[])
{
	int	i;

	i = 0;
	while (i < 256)
	{
		ascii[i] = 0;
		i++;
	}
}

int ft_atoi_base(char *str, char *base)
{
	int		n;
	int		ascii[256];

	shokika(ascii);
	n = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '+'
			|| base[n] == '-' || ascii[(unsigned char)base[n]] != 0)
			return (0);
		ascii[(unsigned char)base[n]] = 1;
		n++;
	}
	if (n <= 1)
		return (0);

	return (basenumber(str, base, n));
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("	+++++--133742", "poneyvif"));
	printf("%d\n", ft_atoi_base("	     ---101010", "01"));
	printf("%d\n", ft_atoi_base(" 	+---539", "0123456789abcdef"));
}
