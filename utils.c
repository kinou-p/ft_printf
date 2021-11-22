/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:40:39 by apommier          #+#    #+#             */
/*   Updated: 2021/11/21 16:53:20 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		ft_putstr_fd("(null)", 1);
	while (s && s[i] != 0)
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr_fd(int n, char type, int *i)
{
	long			nbr;
	unsigned int	unbr;

	nbr = n;
	unbr = n;
	if (nbr < 0 && type != 'u')
	{
		ft_putchar_fd('-', 1);
		nbr *= -1;
		(*i)++;
	}
	if (type != 'u')
	{
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, type, i);
		ft_putchar_fd(nbr % 10 + '0', 1);
	}
	else
	{
		if (unbr >= 10)
			ft_putnbr_fd(unbr / 10, type, i);
		ft_putchar_fd(unbr % 10 + '0', 1);
	}
	(*i)++;
	return (0);
}

int	ft_putnbr_hex(unsigned long n, char type, int *i)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 16)
		ft_putnbr_hex(nbr / 16, type, i);
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
