/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manperez <manperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:47:08 by manperez          #+#    #+#             */
/*   Updated: 2024/01/18 14:30:29 by manperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		if (len < 2)
			return (-1);
		len += ft_putptr(va_arg(args, unsigned long long));
	}
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += check_format(args, *(str + 1));
			if (len == -1)
				return (-1);
			str++;
		}
		else
		{
			len += ft_putchar(*str);
			if (len == -1)
				return (-1);
		}
		str++;
	}
	va_end(args);
	return (len);
}
