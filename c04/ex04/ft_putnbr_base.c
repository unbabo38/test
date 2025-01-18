/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmura <tmura@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:30:17 by tmura             #+#    #+#             */
/*   Updated: 2025/01/18 23:30:29 by tmura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int 	c;
	int		cnt[300]={0};

	i = 0;
	while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
	{
		if(cnt[base[i]]>0)
			return;
		cnt[base[i]]++;
		i++;
	}
	if(i<=1)
		return;
	int		tmp;

	tmp = nbr;
	int		keta;
	keta = 0;
	while(tmp>0)
	{
		tmp/=i;
		keta++;
	}
	tmp = nbr;
	c = 0;
	char num[keta];
	char sixteen[16] = "0123456789ABCDEF";
	while(c<keta)
	{
		if(i==16)
		{
			num[c]=sixteen[tmp%i];
		}
		else
		{
			num[c]=(tmp%i) + '0';
		}
		tmp/=i;
		c++;
	}
	c=0;
	//printf("%d",i);
	if (i > 1)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(1,"-",1);
		}
		while(keta){
			write(1, &num[keta-1], 1);
			keta--;
		}
	}
}
int main()
{
	ft_putnbr_base(1413241,"0123456789ABCDEF");
}
