/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 06:11:16 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 08:51:58 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->order > a->next->order)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_are_indep(int op1, int op2)
{
	if (op1 == SA && op2 == SB)
		return (1);
	else if (op1 == SB && op2 == SA)
		return (1);
	else if ((op1 == RA || op1 == RRA) && (op2 == RB || op2 == RRB))
		return (1);
	else if ((op1 == RB || op1 == RRB) && (op2 == RA || op2 == RRA))
		return (1);
	return (0);
}

int	ft_annule_ops(int op1, int op2)
{
	if (op1 == SA && op2 == SA)
		return (1);
	else if (op1 == SB && op2 == SB)
		return (1);
	else if (op1 == PA && op2 == PB)
		return (1);
	else if (op1 == PB && op2 == PA)
		return (1);
	else if (op1 == RA && op2 == RRA)
		return (1);
	else if (op1 == RRA && op2 == RA)
		return (1);
	else if (op1 == RB && op2 == RRB)
		return (1);
	else if (op1 == RRB && op2 == RB)
		return (1);
	else if (op1 == RR && op2 == RRR)
		return (1);
	else if (op1 == RRR && op2 == RR)
		return (1);
	return (0);
}

int	ft_top_distance_to_chunk(t_stack *a, int size_a,
	int chunk_min, int chunk_max)
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

int	ft_bottom_distance_to_chunk(t_stack *a, int size_a,
	int chunk_min, int chunk_max)
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
