/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:30:40 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:29 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while (k < n - 1 && s1[k] && s2[k] && s1[k] == s2[k])
		k++;
	return ((((unsigned char *)s1)[k]) - ((unsigned char *)s2)[k]);
}
