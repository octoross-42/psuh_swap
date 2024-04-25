/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:38:01 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/19 17:36:54 by octoross         ###   ########.fr       */
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

int	ft_get_order(int new, t_mkstack *aux, int size)
{
	t_stack	*next;
	int		order;

	if (new > aux->max)
	{
		aux->max = new;
		return (size + 1);
	}
	if (new < aux->max)
	{
		order = 1;
		next = aux->stack;
		while (next)
		{
			if (next->n == new)
				return (0);
			if (next->n > new)
				(next->order)++;
			else
				order ++;
			next = next->next;
		}
		return (order);
	}
	return (0);
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

void	ft_init_parsing(t_mkstack *aux, int *size)
{
	aux->stack = NULL;
	aux->next = NULL;
	aux->i = 0;
	*size = 0;
}

t_stack	*ft_checked_args(int argc, char **argv, int *size)
{
	char		**splited;
	t_mkstack	aux;

	ft_init_parsing(&aux, size);
	while (aux.i < argc)
	{
		splited = ft_split(argv[aux.i], " \n\t\n\v\r\f");
		if (!splited || !splited[0])
		{
			if (splited)
				free(splited);
			if (PRINT_ERRORS && !splited)
				ft_printf(ERR_MALLOC);
			else if (PRINT_ERRORS)
				ft_printf(ERR_NO_ARG);
			return (ft_clear_stack(&aux.stack), NULL);
		}
		aux.j = 0;
		while (splited[aux.j])
		{
			if (!ft_add_new_stack(splited[aux.j], &aux, size))
				return (ft_free_until((void **)splited, aux.j, -1),
					ft_clear_stack(&aux.stack), NULL);
			ft_go_to_next_stack(aux.stack, &aux.next);
			free(splited[aux.j]);
			aux.j ++;
		}
		free(splited);
		aux.i ++;
	}
	return (aux.stack->previous = aux.next, aux.stack);
}
