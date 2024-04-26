/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:21:16 by octoross          #+#    #+#             */
/*   Updated: 2024/04/20 17:21:16 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pull_a_reserve(t_sort *sort, int *reserve, int *expected_order)
{
	while (sort->a && (*reserve > 0)
		&& (sort->a->previous->order == sort->a->order - 1))
	{
		ft_do_operation(sort, RRA);
		(*reserve)--;
	}
	*expected_order = sort->a->order - 1;
}

void	ft_push_to_reserve_in_a(t_sort *sort, int *reserve)
{
	ft_do_operation(sort, PA);
	ft_do_operation(sort, RA);
	(*reserve)++;
}

int	ft_get_expected_order(t_stack *a, int max)
{
	while (a->previous->order == max)
	{
		a = a->previous;
		max --;
	}
	return (max);
}

void	ft_push_chunk_to_a(t_sort *sort, int min_chunk,
			int *expected_order, int *reserve)
{
	t_stack	*tmp;
	int		dir;

	while (*expected_order >= min_chunk)
	{
		tmp = sort->b;
		while (tmp && tmp->order >= min_chunk && tmp->order != *expected_order)
			tmp = tmp->next;
		if (tmp && tmp->order == *expected_order)
			dir = RB;
		else
			dir = RRB;
		while (sort->b->order != *expected_order)
		{
			if (((sort->a && (*reserve > 0)
						&& (sort->b->order > sort->a->previous->order))
					|| (*reserve == 0) || !sort->a))
				ft_push_to_reserve_in_a(sort, reserve);
			else
				ft_do_operation(sort, dir);
		}
		ft_do_operation(sort, PA);
		(*expected_order)--;
		ft_pull_a_reserve(sort, reserve, expected_order);
	}
}

void	ft_push_back_to_a(t_sort *sort)
{
	t_chunk	chunk;
	int		expected_order;
	int		reserve;

	chunk.chunk = sort->nbr_chunks;
	expected_order = sort->size;
	reserve = 0;
	chunk.min_chunk = sort->size - sort->size_chunk + 1
		- (chunk.chunk > (sort->nbr_chunks - sort->add_chunk));
	chunk.max_chunk = sort->size;
	while (chunk.chunk > 0 && expected_order > 0)
	{
		ft_push_chunk_to_a(sort, chunk.min_chunk, &expected_order, &reserve);
		chunk.chunk --;
		chunk.max_chunk = chunk.min_chunk - 1;
		chunk.min_chunk = chunk.max_chunk - sort->size_chunk + 1
			- (chunk.chunk > (sort->nbr_chunks - sort->add_chunk));
	}
}
