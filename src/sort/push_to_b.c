/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:14:45 by octoross          #+#    #+#             */
/*   Updated: 2024/04/25 21:06:58 by octoross         ###   ########.fr       */
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

void	ft_push_to_reserve_in_b(t_sort *sort)
{
	ft_do_operation(sort, PB);
	ft_do_operation(sort, RB);
}

int	ft_top_distance_to_chunk(t_stack *a, int size_a, int chunk_min, int chunk_max)
{
	int	top_a;

	if (!a)
		return (-1);
	top_a = 1;
	while (a->next && (top_a + (size_a + 1) % 2) <= size_a / 2)
	{
		if (chunk_min <= a->next->order && a->next->order <= chunk_max)
			return (top_a);
		a = a->next;
		top_a ++;
	}
	return (-1);
}

int	ft_bottom_distance_to_chunk(t_stack *a, int size_a, int chunk_min, int chunk_max)
{
	int	bottom_a;

	if (!a)
		return (-1);
	bottom_a = 1;
	while (bottom_a <= (size_a / 2))
	{
		if (chunk_min <= a->previous->order && a->previous->order <= chunk_max)
			return (bottom_a);
		a = a->previous;
		bottom_a ++;
	}
	return (-1);
}

int	ft_we_swap(t_sort *sort)
{
	if (!(sort->a && sort->a->next && sort->b && sort->b->next))
		return (0);
	if ((sort->a->order > sort->a->next->order) && (sort->b->order < sort->b->next->order))
	{
		ft_do_operation(sort, SS);
		return (1);
	}
	return (0);
}

void	ft_push_to_b(t_sort *sort)
{
	int	chunk;
	int	min_chunk;
	int	max_chunk;
	int	min_next_chunk;
	int	max_next_chunk;
	int	dir;
	int	bottom_a;
	int	top_a;
	
	chunk = 1;
	min_chunk = 1;
	max_chunk = sort->size_chunk;
	min_next_chunk = max_chunk + 1;
	max_next_chunk = min_next_chunk + sort->size_chunk - 1 + ((chunk + 1) > (sort->nbr_chunks - sort->add_chunk));	
	while (chunk <= sort->nbr_chunks)
	{
		bottom_a = ft_bottom_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
		top_a = ft_top_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
		while (sort->a && (bottom_a > 0 || top_a > 0 || (min_chunk <= sort->a->order && sort->a->order <= max_chunk)))
		{
			// printf("size a : %d %d\n", sort->size_a, (sort->size_a / 2));
			// printf("min %d max %d next min %d max %d\n", min_chunk, max_chunk, min_next_chunk, max_next_chunk);
			// printf("bottom %d up %d\n\n", bottom_a, top_a);
			// ft_print_stacks(sort->a, sort->b);
			if (ft_we_swap(sort))
			{
				bottom_a = ft_bottom_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
				top_a = ft_top_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
			}
			if (!(min_chunk <= sort->a->order && sort->a->order <= max_chunk))
			{
				if ((top_a > 0 && top_a < bottom_a) || (bottom_a < 0))
					dir = RA;
				else if (bottom_a > 0)
					dir = RRA;
				while (min_chunk > sort->a->order || sort->a->order > max_chunk)
				{
					if (min_next_chunk <= sort->a->order && sort->a->order <= max_next_chunk)
						ft_push_to_reserve_in_b(sort);
					else
						ft_do_operation(sort, dir);
				}
			}
		
			ft_do_operation(sort, PB);
			bottom_a = ft_bottom_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
			top_a = ft_top_distance_to_chunk(sort->a, sort->size_a, min_chunk, max_chunk);
		}
		ft_pull_b_reserve(sort, min_next_chunk, max_next_chunk);
		chunk ++;
		min_chunk = min_next_chunk;
		max_chunk = max_next_chunk;
		min_next_chunk = max_chunk + 1;
		max_next_chunk = min_next_chunk + sort->size_chunk - 1 + ((chunk + 1) > (sort->nbr_chunks - sort->add_chunk));	
	}
}
