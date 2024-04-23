/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:34:30 by octoross          #+#    #+#             */
/*   Updated: 2023/10/18 18:34:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_sort *sort)
{
	t_stack	*a;
	int		order;

	if (sort->b)
		return (0);
	a = sort->a;
	order = 1;
	while (a)
	{
		if (a->order != order)
			return (0);
		order ++;
		a = a->next;
	}
	return (1);
}

void	ft_get_closer_of_chunk_n_in_b(t_sort *sort, int chunk_min, int chunk_max)
{
	static	int top_a = 0;
	static	int bottom_a = 0;
	t_stack	*next;

	if (chunk_min <= sort->a->order && sort->a->order <= chunk_max)
	{
		ft_do_operation(sort, PB);
		return ;
	}
	next = sort->a->next;
	if (!top_a && (bottom_a != -1))
	{
		top_a = 1;
		while (next && top_a <= sort->size_a / 2)
		{
			if (next->order >= chunk_min && next->order <= chunk_max)
				break ;
			top_a ++;
			next = next->next;
		}
		if (next->order < chunk_min || next->order > chunk_max)
			top_a = -1;
	}
	next = sort->a->previous;
	if (!bottom_a && (bottom_a != -1))
	{
		bottom_a = 1;
		while (next && bottom_a < sort->size_a / 2)
		{
			if (next->order >= chunk_min && next->order <= chunk_max)
				break ;
			bottom_a ++;
			next = next->previous;
		}
		if (next->order < chunk_min || next->order > chunk_max)
			bottom_a = -1;
	}
	if (bottom_a == -1 || (top_a > 0 && top_a <= bottom_a))
	{
		while (sort->a->order < chunk_min || sort->a->order > chunk_max)
		{
			ft_do_operation(sort, RA);
			if (bottom_a > 0)
				bottom_a ++;
		}
		top_a = 0;
	}
	else
	{
		while (sort->a->order < chunk_min || sort->a->order > chunk_max)
		{
			ft_do_operation(sort, RRA);
			if (top_a > 0)
				top_a ++;
		}
		bottom_a = 0;
	}
	ft_do_operation(sort, PB);
}


void	ft_sort(t_sort *s)
{
	if (s->size <= 1)
		return ;
	if (s->size == 2)
	{
		if (s->a->order == 1)
			return ;
		ft_do_operation(s, SA);
		return ;
	}
	ft_chunks_sort(s);
	// printf("ops : %d\n", ft_optimise_ops(s->nbr_ops, &s->ops));
}

// TODO changer printerror a 0