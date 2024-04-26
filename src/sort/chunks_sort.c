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

// void	ft_sort_to_reserve(int order, t_sort *sort, int *reserve)
// {
// 	int	nbr_rra;
// 	int	nbr_ra;
// 	t_stack	*tmp;
// 	int		i;

// 	nbr_rra = 1;
// 	tmp = sort->a->previous;
// 	while (nbr_rra <= *reserve && tmp->order + 1 != order)
// 	{
// 		nbr_rra ++;
// 		tmp = tmp->previous;
// 	}
// 	nbr_ra = sort->size_a - nbr_rra;
// 	i = 0;
// 	if (nbr_ra < nbr_rra)
// 	{
// 		while (i < nbr_ra)
// 		{
// 			ft_do_operation(sort, RA);
// 			i ++;
// 		}
// 		ft_do_operation(sort, PA);
// 		while (i > 0)
// 		{
// 			ft_do_operation(sort, RRA);
// 			i --;
// 		}
// 	}
// 	else
// 	{
// 		while (i < nbr_rra)
// 		{
// 			ft_do_operation(sort, RRA);
// 			i ++;
// 		}
// 		ft_do_operation(sort, PA);
// 		while (i > 0)
// 		{
// 			ft_do_operation(sort, RA);
// 			i --;
// 		}
// 	}
// 	(*reserve) ++;
// }

void	ft_pull_a_reserve(t_sort *sort, int *reserve, int *expected_order)
{
	while (sort->a && (*reserve > 0) && (sort->a->previous->order == sort->a->order - 1))
	{
		// printf("on pull : %d\n", tmp->order);
		ft_do_operation(sort, RRA);
		(*reserve) --;
	}
	*expected_order = sort->a->order - 1;
}

void	ft_push_to_reserve_in_a(t_sort *sort, int *reserve)
{
	ft_do_operation(sort, PA);
	ft_do_operation(sort, RA);
	(*reserve) ++;
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

void	ft_push_back_to_a(t_sort *sort)
{
	int	chunk;
	int	min_chunk;
	int	max_chunk;
	int	expected_order;
	int	reserve;
	int	dir;
	t_stack	*tmp;

	chunk = sort->nbr_chunks;
	expected_order = sort->size;
	reserve = 0;
	min_chunk = sort->size - sort->size_chunk + 1 - (chunk > (sort->nbr_chunks - sort->add_chunk)); 
	max_chunk = sort->size;
	while (chunk > 0 && expected_order > 0)
	{
		while (expected_order >= min_chunk)
		{
			// ft_print_stacks(sort->a, sort->b);
			// printf("expected : %d min chink : %d\n", expected_order, min_chunk);
			tmp = sort->b;
			while (tmp && tmp->order >= min_chunk && tmp->order != expected_order)
				tmp = tmp->next;
			if (tmp && tmp->order == expected_order)
				dir = RB;
			else
				dir = RRB;
			// printf("on est la\n");
			while (sort->b->order != expected_order)
			{
				// printf("why though\n");
				if (((sort->a && (reserve > 0) && (sort->b->order > sort->a->previous->order)) || (reserve == 0) || !sort->a))
				{
					// printf("push to reserve : %d\n", sort->b->order);
					// ft_print_stacks(sort->a, sort->b);
					ft_push_to_reserve_in_a(sort, &reserve);
					// printf("expected : %d, reserve %d, min %d max : %d\n", expected_order, reserve, min_chunk, max_chunk);
					// ft_print_stacks(sort->a, sort->b);
				}
				else
					ft_do_operation(sort, dir);
			}
			ft_do_operation(sort, PA);
			expected_order --;
			// printf("on a push maintenant reserve : %d\n", reserve);
			ft_pull_a_reserve(sort, &reserve, &expected_order);
			// printf("boon c'était pas ca\n");
			
			// ft_print_stacks(sort->a, sort->b);
			// printf("expected : %d, reserve %d, min %d max : %d\n\n", expected_order, reserve, min_chunk, max_chunk);
		}
		chunk --;
		max_chunk = min_chunk - 1;
		min_chunk = max_chunk - sort->size_chunk + 1 - (chunk > (sort->nbr_chunks - sort->add_chunk));
	}
}

void	ft_chunks_sort(t_sort *sort)
{
	ft_push_to_b(sort);
	// ft_print_stacks(sort->a, sort->b);
	ft_push_back_to_a(sort);
}

