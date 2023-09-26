/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:14:24 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:24 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	char			*str;

	k = 0;
	str = ft_strdup(s);
	if (!s || !f)
		return (NULL);
	if (!str)
		return (NULL);
	while (str[k])
	{
		str[k] = f(k, str[k]);
		k++;
	}
	return (str);
}
