/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manperez <manperez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:02:23 by manperez          #+#    #+#             */
/*   Updated: 2024/01/17 17:47:12 by manperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		if (ptr >= 16)
		{
			len += ft_putptr(ptr / 16);
			len += ft_putptr(ptr % 16);
		}
		else
		{
			if (ptr < 10)
				len += ft_putchar(ptr + '0');
			else
				len += ft_putchar((ptr - 10) + 'a');
		}
	}
	return (len);
}
