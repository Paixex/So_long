/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:27:07 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:52:44 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unsignednbr(unsigned int k, int *len)
{
	if (k > 9)
		ft_unsignednbr(k / 10, len);
	ft_putchar_len(k % 10 + '0', len);
}
