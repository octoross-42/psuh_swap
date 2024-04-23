/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:39 by octoross          #+#    #+#             */
/*   Updated: 2023/10/17 18:04:39 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack *a)
{
	int	order;
	int	n;

	if (!a || !a->next)
		return (0);
	order = a->order;
	n = a->n;
	a->n = a->next->n;
	a->order = a->next->order;
	a->next->n = n;
	a->next->order = order;
	return (1);
}

int	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*b_start;

	if (!(*b))
		return (0);
	b_start = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = b_start->previous;
	if (*a)
		b_start->previous = (*a)->previous;
	else
		b_start->previous = b_start;
	b_start->next = *a;
	if (b_start->next)
		b_start->next->previous = b_start;
	*a = b_start;
	return (1);
}

int	ft_double_swap(t_sort *sort)
{
	int	done;

	done = ft_swap(sort->a);
	done += ft_swap(sort->b);
	return (done > 0);
}
