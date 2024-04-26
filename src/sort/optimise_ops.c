/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:09:07 by octoross          #+#    #+#             */
/*   Updated: 2024/04/22 17:09:07 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rm_op(t_operations **ops, t_operations *op)
{
	if (!(op->previous->next))

		*ops = op->next;
	else
		op->previous->next = op->next;
	if (op->next)
		op->next->previous = op->previous;
	free(op);
}

t_operations	*ft_rm_2ops(t_operations **ops, t_operations *op1, t_operations *op2)
{
	t_operations	*tmp;

	tmp = op1->previous;
	if (!(op1->previous->next) && (op1->next != op2))
		tmp = op1->next;
	else if (!(op1->previous->next))
		tmp = op2->next;
	ft_rm_op(ops, op1);
	ft_rm_op(ops, op2);
	return (tmp);
}

t_operations	*ft_possible_merge_ops(t_operations **ops, t_operations *op)
{
	if ((op->op == SA && op->next->op == SB) || (op->op == SB && op->next->op == SA))
	{
		ft_rm_op(ops, op->next);
		op->op = SS;
	}
	else if ((op->op == RA && op->next->op == RB) || (op->op == RB && op->next->op == RA))
	{
		ft_rm_op(ops, op->next);
		op->op = RR;
	}
	else if ((op->op == RRA && op->next->op == RRB) || (op->op == RRB && op->next->op == RRA))
	{
		ft_rm_op(ops, op->next);
		op->op = RRR;
	}
	return (op->next);
}

int	ft_synthetise_ops(int nbr_ops, t_operations **ops)
{
	t_operations	*next;
	t_operations	*indep;

	next = *ops;
	while (next && next->next)
	{
		indep = next;
		while (indep->next && ft_are_indep(indep->op, indep->next->op))
			indep = indep->next;
		if (ft_annule_ops(indep->next->op, next->op))
			next = ft_rm_2ops(ops, next, indep->next);
		else
			next = next->next;
	}
	next = *ops;
	while (next && next->next)
		next = ft_possible_merge_ops(ops, next);
	return (nbr_ops);
}
