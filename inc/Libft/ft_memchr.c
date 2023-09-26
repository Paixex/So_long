/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:39:20 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:49:02 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;

	s1 = (char *)s;
	while (n-- > 0)
	{
		if ((unsigned char) *s1 == (unsigned char)c)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
