/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:23:20 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:49:07 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	k;
	unsigned char	*l;
	unsigned char	*j;

	l = (unsigned char *)s1;
	j = (unsigned char *)s2;
	k = 0;
	while (k < n)
	{
		if (l[k] != j[k])
			return (l[k] - j[k]);
		k++;
	}
	return (0);
}
