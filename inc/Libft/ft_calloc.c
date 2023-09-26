/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:23:16 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:47:28 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nrmem, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nrmem);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', (size * nrmem));
	return (ptr);
}
