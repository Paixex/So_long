/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:32:43 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:55:05 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pointer(size_t k, int *len)
{
	if (k == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_hexa(k, 'x', len);
}
