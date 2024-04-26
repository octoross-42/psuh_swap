/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:22 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 04:56:16 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_error_format(const char *format)
{
	int	i;
	int	nbr_successive_pourcents;

	nbr_successive_pourcents = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i == 0 || format[i - 1] != '%')
				nbr_successive_pourcents = 1;
			else
				nbr_successive_pourcents ++;
		}
		else
			nbr_successive_pourcents = 0;
		i ++;
	}
	if (format[i - 1] == '%' && (nbr_successive_pourcents % 2))
		return (1);
	return (0);
}

static int	ft_format(char c, va_list *ap, int *i)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'p')
		return (write(1, "0x", 2)
			+ ft_putnbr(va_arg(*ap, unsigned long), 1, 16));
	else if (c == 'd')
		return (ft_putnbr(va_arg(*ap, int), 1, 10));
	else if (c == 'i')
		return (ft_putnbr(va_arg(*ap, int), 1, 10));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int), 1, 10));
	else if (c == 'x')
		return (ft_putnbr(va_arg(*ap, int), 1, 16));
	else if (c == 'X')
		return (ft_putnbr(va_arg(*ap, int), 0, 16));
	else if (c == '%')
		return (ft_putchar('%'));
	else
	{
		(*i)--;
		return (ft_putchar('%'));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	if (!format || ft_error_format(format))
		return (-1);
	len = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '\\')
			ft_putchar(format[i + 1]);
		else if (format[i] == '%')
			len += ft_format(format[i + 1], &ap, &i);
		else
			len += ft_putchar(format[i]);
		i ++;
	}
	va_end(ap);
	return (len);
}
