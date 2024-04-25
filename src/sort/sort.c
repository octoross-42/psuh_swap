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
	ft_chunks_sort(s);
	// printf("ops : %d\n", ft_optimise_ops(s->nbr_ops, &s->ops));
}

// TODO changer printerror a 0