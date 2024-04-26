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

void	ft_init_sort(t_sort *sort, t_stack *a, int size)
{
	sort->a = a;
	sort->b = NULL;
	sort->size_a = size;
	sort->size_b = 0;
	sort->size = size;
	sort->ops = NULL;
	if (size <= 5)
		sort->nbr_chunks = TINY_NBR_CHUNKS;
	else if (size <= 10)
		sort->nbr_chunks = SMALL_NBR_CHUNKS;
	else if (size <= 150)
		sort->nbr_chunks = MEDIUM_NBR_CHUNKS;
	else
		sort->nbr_chunks = BIG_NBR_CHUNKS;
	sort->size_chunk = sort->size / sort->nbr_chunks;
	sort->add_chunk = sort->size - sort->size_chunk * sort->nbr_chunks;
}

void	ft_sort_three(t_sort *sort)
{
	while (!ft_is_sorted(sort->a))
	{
		if (sort->a->order - 1 == sort->a->next->order)
			ft_do_operation(sort, SA);
		else if ((sort->a->order == sort->a->previous->order + 1)
			&& (sort->a->order + 1 == sort->a->next->order))
			ft_do_operation(sort, RRA);
		else
			ft_do_operation(sort, RA);
	}
}

void	ft_push_head_to_b(t_sort *s, int top)
{
	int		dir;
	t_stack	*next;

	next = s->a;
	dir = 0;
	while (next && next->order != (s->size - 2 - top))
	{
		dir ++;
		next = next->next;
	}
	if (!dir)
		ft_do_operation(s, PB);
	else
	{
		if (dir > (s->size_a / 2))
			dir = RRA;
		else
			dir = RA;
		while (s->a->order != (s->size - 2 - top))
			ft_do_operation(s, dir);
		ft_do_operation(s, PB);
	}
}

void	ft_sort_five(t_sort *s)
{
	int		top;

	top = s->size - 3;
	while (top > 0)
	{
		ft_push_head_to_b(s, top);
		top --;
	}
	ft_sort_three(s);
	top = s->size - 3;
	while (top > 0)
	{
		ft_do_operation(s, PA);
		top --;
	}
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
	if (s->size <= 5)
	{
		ft_sort_five(s);
		return ;
	}
	else
	{
		ft_push_to_b(s);
		ft_push_back_to_a(s);
	}
}
