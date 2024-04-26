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

int	ft_chunk_is_sorted(t_stack *a)
{
	int	error;

	error = 0;
	while (a->next)
	{
		if (a->order > a->next->order)
			return (error);
		error ++;
		a = a->next;
	}
	return (-1);
}

void	ft_sort_three(t_sort *sort)
{
	int	error;

	if (!(sort->a && sort->a->next && sort->a->next->next))
		return ;
	error = ft_chunk_is_sorted(sort->a);
	if (error < 0)
		return ;
	if (error == 0 && ((sort->a->order < sort->a->previous->order) || (sort->a->next->order > sort->a->previous->order)))
	{
		ft_do_operation(sort, SA);
		if (sort->b && sort->b->next && sort->b->next->next && (sort->b->next->next->order > sort->b->order && sort->b->order < sort->b->next->order && sort->b->next->next->order < sort->b->next->order))
			ft_do_operation(sort, SB);
		error = ft_chunk_is_sorted(sort->a);
		if (error < 0)
			return ;
	}
	else if (error == 1)
	{
		ft_do_operation(sort, RRA);
		if (sort->a->order > sort->a->next->order)
		{
			ft_do_operation(sort, SA);
			if (sort->b && sort->b->next && sort->b->next->next && (sort->b->next->next->order > sort->b->order && sort->b->order < sort->b->next->order && sort->b->next->next->order < sort->b->next->order))
				ft_do_operation(sort, SB);
		}
		return ;
	}
	if (sort->a->order > sort->a->next->order)
		ft_do_operation(sort, RA);
	else
		ft_do_operation(sort, RRA);
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
	if (s->size == 3)
		ft_sort_three(s);
	else
		ft_chunks_sort(s);
	// printf("ops : %d\n", ft_optimise_ops(s->nbr_ops, &s->ops));
}

// TODO changer printerror a 0