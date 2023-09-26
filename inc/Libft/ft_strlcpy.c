/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:16:00 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:16 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	j;

	k = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size != '\0')
	{
		while ((src[k]) != '\0' && (k < (size - 1)))
		{
			dest[k] = src[k];
			k++;
		}
		dest[k] = '\0';
	}
	return (j);
}
