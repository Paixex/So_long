/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:21:05 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:44 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	k;
	size_t	j;
	char	*substr;

	if (!s)
		return (0);
	k = 0;
	j = start;
	if (start > ft_strlen(s))
	{
		substr = (char *)malloc(sizeof (char));
		*substr = 0;
		return (substr);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (j < ft_strlen(s) && k < len)
		substr[k++] = s[j++];
	substr[k] = '\0';
	return (substr);
}
