/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apommier <alexpomms@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:23:26 by apommier          #+#    #+#             */
/*   Updated: 2021/11/13 13:10:11 by apommier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, char type, int *i);
int	ft_putnbr_hex(unsigned long n, char type, int *i);
int	ft_putpointer(unsigned long nbr, char type, int *i);
int	ft_putchar_fd(char c, int fd);
int	ft_printf(const char *input, ...);
int	next_char(const char *input, int i);
int	set_type(char type, va_list *ap);
int	ft_strlen(const char *s);

#endif
