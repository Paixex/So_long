/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:48:37 by digil-pa          #+#    #+#             */
/*   Updated: 2023/09/20 17:17:36 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printf_checker(char s, va_list *arg, int *len, int *i)
{
	if (s == 'c')
		ft_putchar_len(va_arg (*arg, int), len);
	else if (s == 's')
		ft_putstr(va_arg (*arg, char *), len);
	else if (s == 'p')
		ft_pointer(va_arg (*arg, size_t), len);
	else if (s == 'i' || s == 'd')
		ft_putnbr_len(va_arg (*arg, int), len);
	else if (s == 'u')
		ft_unsignednbr(va_arg (*arg, unsigned int), len);
	else if (s == 'x')
		ft_hexa(va_arg (*arg, unsigned int), 'x', len);
	else if (s == 'X')
		ft_hexa(va_arg (*arg, unsigned int), 'X', len);
	else if (s == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	int		k;
	int		len;
	va_list	arg;

	k = 0;
	len = 0;
	va_start (arg, format);
	while (format[k] != '\0')
	{
		if (format[k] == '%')
		{
			k++;
			ft_printf_checker(format[k], &arg, &len, &k);
			k++;
		}
		else
		{
			ft_putchar_len((char)format[k], &len);
			k++;
		}
	}
	va_end (arg);
	return (len);
}
