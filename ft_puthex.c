/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manperez <manperez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:27:40 by manperez          #+#    #+#             */
/*   Updated: 2024/01/17 17:54:33 by manperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_util(unsigned int num, int len, char hex)
{
	if (num < 10)
	{
		len += ft_putchar(num + '0');
		if (len == -1)
			return (-1);
	}
	else
	{
		len += ft_putchar((num - 10) + hex);
		if (len == -1)
			return (-1);
	}
	return (len);
}

int	ft_puthex(unsigned int num, const char c)
{
	char	hex;
	int		len;

	len = 0;
	hex = 'a';
	if (c == 'X')
		hex = 'A';
	if (num >= 16)
	{
		len += ft_puthex((num / 16), c);
		if (len == -1)
			return (-1);
		len += ft_puthex((num % 16), c);
		if (len == -1)
			return (-1);
	}
	else
		len += ft_puthex_util(num, len, hex);
	return (len);
}
