/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:00:48 by octoross          #+#    #+#             */
/*   Updated: 2023/10/18 18:00:48 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_op(int op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
	else if (op == PA)
		write(1, "pa\n", 3);
	else if (op == PB)
		write(1, "pb\n", 3);
	else if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else if (op == RRR)
		write(1, "rrr\n", 4);
	else if (op == RR)
		write(1, "rr\n", 3);
}

void	ft_print_operations(t_operations *operations)
{
	t_operations	*next;

	if (!operations)
		return ;
	ft_print_op(operations->op);
	next = operations->next;
	free(operations);
	ft_print_operations(next);
}

int	ft_add_operation(int op, t_operations **operations)
{
	t_operations	*next;
	t_operations	*new;

	if (!operations)
		return (1);
	new = (t_operations *)malloc(sizeof(t_operations));
	if (!new)
		return (1);
	(new)->next = NULL;
	(new)->op = op;
	next = *operations;
	while (next && next->next)
		next = next->next;
	if (*operations)
	{
		next->next = new;
		new->previous = next;
	}
	else
		*operations = new;
	(*operations)->previous = new;
	return (0);
}

int	ft_do_op(t_sort *sort, int op)
{
	if (op == SA)
		return (ft_swap(sort->a));
	else if (op == SB)
		return (ft_swap(sort->b));
	else if (op == SS)
		return (ft_double_swap(sort));
	else if (op == PA)
		return (ft_push(&(sort->a), &(sort->b)));
	else if (op == PB)
		return (ft_push(&(sort->b), &(sort->a)));
	else if (op == RA)
		return (ft_rotate(&(sort->a)));
	else if (op == RB)
		return (ft_rotate(&(sort->b)));
	else if (op == RR)
		return (ft_double_rotate(sort));
	else if (op == RRA)
		return (ft_reverse_rotate(&(sort->a)));
	else if (op == RRB)
		return (ft_reverse_rotate(&(sort->b)));
	else if (op == RRR)
		return (ft_double_reverse_rotate(sort));
	return (0);
}

void	ft_do_operation(t_sort *sort, int op)
{
	int	done;

	done = ft_do_op(sort, op);
	if (!done)
		return ;
	sort->size_a += (op == PA) * (sort->size_b > 0)
		- (op == PB) * (sort->size_a > 0);
	sort->size_b += (op == PB) * (sort->size_a > 0)
		- (op == PA) * (sort->size_b > 0);
	ft_add_operation(op, &(sort->ops));
}
