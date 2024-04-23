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

int	ft_optimise_ops(int nbr_ops, t_operations **ops)
{
	t_operations	*next;
	t_operations	*indep;

	next = *ops;
	while (next && next->next)
	{
		indep = next;
		while (indep->next && ft_are_indep(indep->op, indep->next->op))
		{
			
			indep = indep->next;
		}
		
	}
	return (nbr_ops);
}
