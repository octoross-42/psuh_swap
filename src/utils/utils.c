/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:33:19 by octoross          #+#    #+#             */
/*   Updated: 2023/10/17 20:33:19 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_nbr_digits(unsigned long nbr)
{
	int	nbr_digits;

	nbr_digits = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		nbr_digits ++;
	}
	return (nbr_digits);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}
char	ft_lowercasetouppercase(char c)
{
	return (c + ('A' - 'a'));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = 0;
	while (s[len])
		len ++;
	return (len);
}


