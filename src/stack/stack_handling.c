/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:02:50 by octoross          #+#    #+#             */
/*   Updated: 2023/10/18 18:02:50 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_in_stack(int arg, t_stack *s)
{
	while (s)
	{
		if (s->n == arg)
			return (1);
		s = s->next;
	}
	return (0);
}

void	ft_go_to_next_stack(t_stack *start, t_stack **next)
{
	if (*next)
		*next = (*next)->next;
	else
		*next = start;
}

int	ft_add_new_stack(char *splited, t_mkstack *aux, int *size)
{
	t_stack		*new;
	t_valid_int	v;

	if (!ft_is_int_valid(&v, splited, aux, *size))
		return (0);
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->n = v.n;
	new->next = NULL;
	new->previous = aux->next;
	if (aux->next)
		aux->next->next = new;
	if (!aux->stack)
		aux->stack = new;
	new->order = v.order;
	(*size)++;
	return (1);
}

void	ft_clear_stack(t_stack **stack)
{
	if (!stack || !(*stack))
		return ;
	ft_clear_stack(&((*stack)->next));
	free(*stack);
	*stack = 0;
}

void	ft_clear_stacks(t_stack **a, t_stack **b)
{
	ft_clear_stack(a);
	ft_clear_stack(b);
}
