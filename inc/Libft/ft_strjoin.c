/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:27:24 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:07 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	k;
	size_t	j;
	size_t	len;
	char	*dest;

	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[k])
		dest[j++] = s1[k++];
	k = 0;
	while (s2[k])
		dest[j++] = s2[k++];
	dest[j] = '\0';
	return (dest);
}
