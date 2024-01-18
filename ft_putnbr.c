/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manperez <manperez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:35:35 by manperez          #+#    #+#             */
/*   Updated: 2024/01/17 17:49:51 by manperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		num = num * (-1);
		len++;
	}
	if (num >= 10)
	{
		len += ft_putnbr(num / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar((num % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}
