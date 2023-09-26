/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:10:55 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:47:13 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	k;
	int	sinal;
	int	num;

	sinal = 1;
	num = 0;
	k = 0;
	while ((str[k] >= 9 && str[k] <= 13) || str[k] == 32)
		k++;
	if (str[k] == '+' || str[k] == '-')
	{
		if (str[k] == '-')
			sinal *= -1;
		k++;
	}
	while (str[k] >= '0' && str[k] <= '9')
	{
		num = (num * 10) + (str[k] - '0');
			k++;
	}
	return (sinal * num);
}
