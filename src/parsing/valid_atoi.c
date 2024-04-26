/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 05:20:49 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 05:21:20 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checked_atoi(t_valid_int *v, char *s)
{
	long long	atoied;
	int			sign;
	int			i;

	atoied = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i ++;
	sign = (s[i] != '-') * 2 - 1;
	if (s[i] == '-' || s[i] == '+')
		i ++;
	while (s[i] && '0' <= s[i] && s[i] <= '9')
		atoied = atoied * 10 + (s[i ++] - '0');
	while (ft_isspace(s[i]))
		i ++;
	if (s[i] || atoied * sign > INT_MAX || atoied * sign < INT_MIN)
		return (0);
	return (v->is_valid = 1, v->n = atoied * sign, 1);
}

int	ft_is_int_valid(t_valid_int *v, char *splited, t_mkstack *aux, int size)
{
	if (!ft_checked_atoi(v, splited))
	{
		if (PRINT_ERRORS)
			ft_printf(ERR_INT, splited);
		return (0);
	}
	if (!aux->stack)
	{
		v->order = 1;
		aux->max = v->n;
	}
	else
		v->order = ft_get_order(v->n, aux, size);
	if (!v->order)
	{
		if (PRINT_ERRORS)
			ft_printf(ERR_SAME, v->n);
		v->is_valid = 0;
	}
	return (v->is_valid);
}
