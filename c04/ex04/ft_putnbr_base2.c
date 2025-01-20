/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmura <tmura@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:25:41 by tmura             #+#    #+#             */
/*   Updated: 2025/01/20 12:25:43 by tmura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	basenumber(int nbr, char *base, int n)
{
	if (nbr > n - 1)
		basenumber(nbr / n, base, n);
	write(1, &base[nbr % n], 1);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	int		ascii[256];

	shokika(ascii);
	n = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '+'
			|| base[n] == '-' || ascii[(unsigned char)base[n]] != 0)
			return ;
		ascii[(unsigned char)base[n]] = 1;
		n++;
	}
	if (n <= 1)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	basenumber(nbr, base, n);
}
/*
int main(void)
{
	ft_putnbr_base(3242, "0123456789ABCDEF"); // 出力: "CA2"
	ft_putnbr_base(3242, "01");              // 出力: "110010101010"
	ft_putnbr_base(3242, "poneyvif");
	ft_putnbr_base(3242, "001");             // 出力なし (重複あり)
	ft_putnbr_base(3242, "0");               // 出力なし (基数が1以下)
	return 0;
}
*/
