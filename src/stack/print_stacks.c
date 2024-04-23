/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:21:17 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/20 01:23:01 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d : %d", stack->n, stack->order);
		if (stack->next)
			printf("\n");
		stack = stack->next;
	}
	printf("\n");
}

// static int	ft_max_digits(t_stack *a, t_stack *b)
// {
// 	int	nbr_digits;
// 	int	max_digit;
// 	// int	max_serial;
// 	int	max_order;

// 	max_order = 0;
// 	if (a)
// 		max_order = a->max_order;
// 	if (b)
// 		max_order = ft_max(max_order, b->size);
// 	max_digit = 0;
// 	// max_serial = 1;
// 	while (a)
// 	{
// 		nbr_digits = ft_nbr_digits(a->n);
// 		if (nbr_digits > max_digit)
// 			max_digit = nbr_digits;
// 		// nbr_digits = ft_nbr_digits(a->serial);
// 		// if (nbr_digits > max_serial)
// 		// 	max_serial = nbr_digits;
// 		a = a->next;
// 	}
// 	return (ft_nbr_digits(max_order) + max_digit + 7);
// }

static void	ft_print_n_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf(" ");
		i ++;
	}
}

int	ft_max_top(t_stack *a)
{
	int	max;
	int	nbr_digits;

	max = 0;
	while (a)
	{
		nbr_digits = ft_nbr_digits(a->n);
		if (nbr_digits > max)
			max = nbr_digits;
		a = a->next;
	}
	return (max);
}

int	ft_max_order(t_stack *a)
{
	int	max;
	int	nbr_digits;

	max = 0;
	while (a)
	{
		nbr_digits = ft_nbr_digits(a->order);
		if (nbr_digits > max)
			max = nbr_digits;
		a = a->next;
	}
	return (max);
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	int	top_a;
	int	order_a;
	int	size_a;
	int	start;
	int	space_between;

	start = 1;
	space_between = 4;
	top_a = ft_max_top(a);
	order_a = ft_max_order(a);
	size_a = top_a + order_a;
	printf("\033[37;01mstack a");
	ft_print_n_spaces(size_a - 3 + space_between);
	printf("stack b\033[00m\n");
	while (a || b)
	{
		if (a)
		{
			// printf("(%d) ", a->previous->n);
			printf("%d", a->n);
			ft_print_n_spaces(top_a - ft_nbr_digits(a->n));
			printf(" -> \033[37;01m%d\033[00m", a->order);
			ft_print_n_spaces(order_a - ft_nbr_digits(a->order) + space_between);
			a = a->next;
		}
		else if (start)
		{
			printf("(null)");
			ft_print_n_spaces(size_a - 2 + space_between);
		}
		else
			ft_print_n_spaces(size_a + 4 + space_between);
		if (b)
		{
			// printf("(%d) ", b->previous->n);
			printf("%d", b->n);
			ft_print_n_spaces(top_a - ft_nbr_digits(b->n));
			printf(" -> \033[37;01m%d\033[00m", b->order);
			b = b->next;
		}
		else if (start)
			printf("(null)");
		printf("\n");
		start = 0;
	}
	printf("\n");
}
