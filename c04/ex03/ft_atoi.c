/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmura <tmura@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:21:37 by tmura             #+#    #+#             */
/*   Updated: 2025/01/20 13:14:37 by tmura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int		pm;
	int		ans;
	int		i;

	pm = 1;
	ans = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			pm = -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				ans = 10 * ans + str[i] - '0';
				i++;
			}
			break ;
		}
		i++;
	}
	return (pm * ans);
}
int main(){
	printf("%d",ft_atoi("---+--+1234ab567"));
}
