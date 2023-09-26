/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:00:18 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:49:11 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			k;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	k = 0;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (k < n)
	{
		d[k] = s[k];
		k++;
	}
	return (dest);
}
