/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:14:45 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 06:27:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pull_b_reserve(t_sort *sort, int chunk_min, int chunk_max)
{
	t_stack	*tmp;

	tmp = sort->b->previous;
	while (tmp && chunk_min <= tmp->order && tmp->order <= chunk_max)
	{
		ft_do_operation(sort, RRB);
		tmp = tmp->previous;
	}
}

void	ft_push_to_reserve_in_b(t_sort *sort, int chunk)
{
	ft_do_operation(sort, PB);
	if (chunk % 2)
		ft_do_operation(sort, RB);
}

void	ft_roll_to_b(t_sort *sort, int bottom_a, int top_a, t_chunk *chunk)
{
	int		dir;

	if ((top_a > 0 && top_a < bottom_a) || (bottom_a < 0))
		dir = RA;
	else if (bottom_a > 0)
		dir = RRA;
	while (chunk->min_chunk > sort->a->order
		|| sort->a->order > chunk->max_chunk)
	{
		if (chunk->min_next_chunk <= sort->a->order
			&& sort->a->order <= chunk->max_next_chunk)
			ft_push_to_reserve_in_b(sort, chunk->chunk + 1);
		else
			ft_do_operation(sort, dir);
	}
}

void	ft_push_chunk_to_b(t_sort *sort, t_chunk *chunk)
{
	int		bottom_a;
	int		top_a;

	bottom_a = ft_bottom_distance_to_chunk(sort->a,
			sort->size_a, chunk->min_chunk, chunk->max_chunk);
	top_a = ft_top_distance_to_chunk(sort->a,
			sort->size_a, chunk->min_chunk, chunk->max_chunk);
	while (sort->a && (bottom_a > 0 || top_a > 0
			|| (chunk->min_chunk <= sort->a->order
				&& sort->a->order <= chunk->max_chunk)))
	{
		if (!(chunk->min_chunk <= sort->a->order
				&& sort->a->order <= chunk->max_chunk))
			ft_roll_to_b(sort, bottom_a, top_a, chunk);
		ft_push_to_reserve_in_b(sort, chunk->chunk);
		bottom_a = ft_bottom_distance_to_chunk(sort->a,
				sort->size_a, chunk->min_chunk, chunk->max_chunk);
		top_a = ft_top_distance_to_chunk(sort->a,
				sort->size_a, chunk->min_chunk, chunk->max_chunk);
	}
}

void	ft_push_to_b(t_sort *sort)
{
	t_chunk	chunk;

	chunk.chunk = 1;
	chunk.min_chunk = 1;
	chunk.max_chunk = sort->size_chunk;
	chunk.min_next_chunk = chunk.max_chunk + 1;
	chunk.max_next_chunk = chunk.min_next_chunk + sort->size_chunk - 1
		+ ((chunk.chunk + 1) > (sort->nbr_chunks - sort->add_chunk));
	while (chunk.chunk <= sort->nbr_chunks)
	{
		ft_push_chunk_to_b(sort, &chunk);
		chunk.chunk ++;
		chunk.min_chunk = chunk.min_next_chunk;
		chunk.max_chunk = chunk.max_next_chunk;
		chunk.min_next_chunk = chunk.max_chunk + 1;
		chunk.max_next_chunk = chunk.min_next_chunk + sort->size_chunk
			- 1 + ((chunk.chunk + 1) > (sort->nbr_chunks - sort->add_chunk));
	}
}
