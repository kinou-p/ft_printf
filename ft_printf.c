/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <apommier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:22:43 by apommier          #+#    #+#             */
/*   Updated: 2021/11/17 17:05:48 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_type(char type, va_list *ap)
{
	int	printed;

	printed = 0;
	if (type == 'c')
		printed += ft_putchar_fd(va_arg(*ap, int), 1);
	else if (type == 's')
		printed += ft_putstr_fd(va_arg(*ap, char *), 1);
	else if (type == 'd' || type == 'i' || type == 'u')
		printed += ft_putnbr_fd(va_arg(*ap, long), type, &printed);
	else if (type == 'x' || type == 'X')
		printed += ft_putnbr_hex((long)va_arg(*ap, long), type, &printed);
	else if (type == 'p')
	{
		ft_putstr_fd("0x", 1);
		printed += ft_putpointer((long)va_arg(*ap, void *), type, &printed) + 2;
	}
	else if (type == '%')
		printed += ft_putchar_fd('%', 1);
	return (printed);
}

int	ft_putpointer(unsigned long nbr, char type, int *i)
{
	if (nbr >= 16)
		ft_putpointer(nbr / 16, type, i);
	if ((nbr % 16) < 10)
		ft_putchar_fd(nbr % 16 + '0', 1);
	else if (type == 'x' || type == 'p')
		ft_putchar_fd(nbr % 16 - 10 + 'a', 1);
	else if (type == 'X')
	{
		ft_putchar_fd(nbr % 16 - 10 + 'A', 1);
	}
	(*i)++;
	return (0);
}

int	next_char(const char *format, int i)
{
	int	printed;

	printed = 0;
	while (format[i] != '\0' && format[i] != '%')
	{
		write(1, &format[i], 1);
		i++;
		printed ++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	int		printed;
	va_list	ap;

	printed = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] > '\0')
	{
		j = next_char(format, i);
		printed += j;
		i += j;
		if (format[i] == '%')
		{
			printed += set_type(format[i + 1], &ap);
			i += 2;
		}
	}
	va_end(ap);
	return (printed);
}
