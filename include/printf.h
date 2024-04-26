/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:18:02 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 04:56:52 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# define HEXA_BASE "0123456789abcdef"

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "utils.h"

int		ft_putnbr(long n, int lowercase, long base);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	ft_lowercasetouppercase(char c);
int		ft_printf(const char *format, ...);

#endif