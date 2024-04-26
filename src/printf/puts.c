/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:41:03 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 05:23:59 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long	ft_cast_hex(int n)
{
	unsigned int	u;
	long			nbr;

	u = n;
	nbr = u;
	return (nbr);
}

int	ft_putnbr(long n, int lowercase, long base)
{
	int			len;

	len = 0;
	if (n < 0 && base == 10)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n < 0 && base == 16)
		n = ft_cast_hex(n);
	if (n >= base)
		len += ft_putnbr(n / base, lowercase, base);
	if (lowercase || (n % base < 10))
		ft_putchar(HEXA_BASE[n % base]);
	else
		ft_putchar(ft_lowercasetouppercase(HEXA_BASE[n % base]));
	len ++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
