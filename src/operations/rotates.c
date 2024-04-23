/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:09:12 by octoross          #+#    #+#             */
/*   Updated: 2023/10/17 18:09:12 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack **a)
{
	t_stack	*next;

	if (!(*a) || !(*a)->next)
		return (0);
	next = (*a)->next;
	(*a)->previous->next = *a;
	(*a)->next = NULL;
	*a = next;
	return (1);
}

int	ft_reverse_rotate(t_stack **a)
{
	t_stack	*start;

	if (!(*a) || !(*a)->next)
		return (0);
	start = *a;
	*a = (*a)->previous;
	(*a)->next = start;
	(*a)->previous->next = NULL;
	return (1);
}

int	ft_double_rotate(t_sort *sort)
{
	int	done;

	done = ft_rotate(&(sort->a));
	done += ft_rotate(&(sort->b));
	return (done > 0);
}

int	ft_double_reverse_rotate(t_sort *sort)
{
	int	done;

	done = ft_reverse_rotate(&(sort->a));
	done += ft_reverse_rotate(&(sort->b));
	return (done > 0);
}
