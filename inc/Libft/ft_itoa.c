/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:50:59 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:47:50 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen_with_minus(int num)
{
	unsigned int	numlen;

	numlen = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		numlen++;
	while (num != 0)
	{
		num = num / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	unsigned int	nlen;
	char			*s;
	unsigned int	num;

	nlen = ft_intlen_with_minus(n);
	s = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (n == 0)
		s[0] = '0';
	s[nlen] = '\0';
	while (num != 0)
	{
		s[nlen - 1] = (num % 10) + '0';
		num = num / 10;
		nlen--;
	}
	return (s);
}
