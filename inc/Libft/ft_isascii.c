/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:15:55 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:47:40 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int k)
{
	if (k >= 0 && k <= 127)
		return (1);
	return (0);
}
