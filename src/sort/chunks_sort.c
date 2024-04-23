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

void	ft_push_to_b(t_sort *sort)
{
	int	i;
	int	chunk;
	int	min_chunk;
	int	max_chunk;
	int	j;

	i = 1;
	chunk = 0;
	// printf("nbr_chunks : %d\n", sort->nbr_chunks);
	while (chunk < sort->nbr_chunks)
	{
		min_chunk = i;
		max_chunk = i - 1 + sort->size_chunk + (chunk >= (sort->nbr_chunks - sort->add_chunk));
		// printf("min : %d, max : %d\n", min_chunk, max_chunk);
		j = min_chunk;
		while (j <= max_chunk)
		{
			ft_get_closer_of_chunk_n_in_b(sort, min_chunk, max_chunk);
			j ++;
			i ++;
		}
		chunk ++; 
	}
	// printf("\n");
}

void	ft_sort_to_reserve(int order, t_sort *sort, int *reserve)
{
	int	nbr_rra;
	int	nbr_ra;
	t_stack	*tmp;
	int		i;

	nbr_rra = 1;
	tmp = sort->a->previous;
	while (nbr_rra <= *reserve && tmp->order + 1 != order)
	{
		nbr_rra ++;
		tmp = tmp->previous;
	}
	nbr_ra = sort->size_a - nbr_rra;
	i = 0;
	if (nbr_ra < nbr_rra)
	{
		while (i < nbr_ra)
		{
			ft_do_operation(sort, RA);
			i ++;
		}
		ft_do_operation(sort, PA);
		while (i > 0)
		{
			ft_do_operation(sort, RRA);
			i --;
		}
	}
	else
	{
		while (i < nbr_rra)
		{
			ft_do_operation(sort, RRA);
			i ++;
		}
		ft_do_operation(sort, PA);
		while (i > 0)
		{
			ft_do_operation(sort, RA);
			i --;
		}
	}
	(*reserve) ++;
}

void	ft_pull_reserve(t_sort *sort, int *reserve, int *expected_order)
{
	t_stack	*tmp;

	tmp = sort->a->previous;
	while (tmp && (*reserve > 0) && tmp->order == *expected_order)
	{
		// printf("on pull : %d\n", tmp->order);
		ft_do_operation(sort, RRA);
		(*expected_order) --;
		(*reserve) --;
		tmp = tmp->previous;
	}
}

void	ft_push_to_reserve(t_sort *sort, int *reserve)
{
	ft_do_operation(sort, PA);
	ft_do_operation(sort, RA);
	(*reserve) ++;
}

void	ft_push_back_to_a(t_sort *sort)
{
	int	chunk;
	int	min_chunk;
	int	max_chunk;
	int	expected_order;
	int	reserve;
	int	dir;
	t_stack	*tmp;
	// int		already_done;

	chunk = sort->nbr_chunks;
	// printf("nbr_chunks : %d\n", sort->nbr_chunks);
	// already_done = 0;
	while (chunk > 0)
	{
		// printf("chunk : %d\n", chunk);
		reserve = 0;
		min_chunk = sort->size - sort->size_a + 1 - sort->size_chunk - (chunk > (sort->nbr_chunks - sort->add_chunk));
		max_chunk = sort->size - sort->size_a;
		// printf("min : %d, max : %d\n", min_chunk, max_chunk);
		expected_order = max_chunk;
		// printf("expected_order : %d\n", expected_order);
		// printf("min : %d, max : %d\n", min_chunk, max_chunk);
			
		while (expected_order >= min_chunk)
		{
			// printf("min : %d, max : %d\n", min_chunk, max_chunk);
			// // printf("expected_order : %d\n", expected_order);
			// ft_print_stacks(sort->a, sort->b);
			tmp = sort->b;
			while (tmp && tmp->order >= min_chunk && tmp->order != expected_order)
				tmp = tmp->next;
			if (tmp->order == expected_order)
				dir = RB;
			else
				dir = RRB;
			// if (expected_order != already_done)
			// 	{
					// printf("expected_order : %d, order : %d\n", expected_order, sort->b->order);
					// ft_print_stacks(sort->a, sort->b);
			// 		already_done = expected_order;
			// 	}
			while (sort->b->order != expected_order)
			{
				if (((sort->a && sort->b->order > sort->a->previous->order) || !sort->a) && sort->b->order != expected_order)
					ft_push_to_reserve(sort, &reserve);
				else
					ft_do_operation(sort, dir);
			}
			ft_do_operation(sort, PA);
			expected_order --;
			ft_pull_reserve(sort, &reserve, &expected_order);
		}
		chunk --; 
	}
	// printf("\n");
}

void	ft_chunks_sort(t_sort *sort)
{
	ft_push_to_b(sort);
	// ft_print_stacks(sort->a, sort->b);
	// printf("now back to b ! \n\n");
	ft_push_back_to_a(sort);
}

