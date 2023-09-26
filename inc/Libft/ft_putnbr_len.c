/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:33:38 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 16:54:44 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_len(int n, int *len)
{
	int	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr_len(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr_len(nbr / 10, len);
		ft_putchar_len(nbr % 10 + '0', len);
	}
}
