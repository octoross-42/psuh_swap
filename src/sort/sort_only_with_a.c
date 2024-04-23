/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_only_with_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:03:11 by octoross          #+#    #+#             */
/*   Updated: 2024/04/23 17:14:37 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_only_with_a(t_sort *sort)
{
	int				max;
	t_operations	*min_ops;
	int				min_nbr_ops;
	int				nbr_ops;

	min_ops = NULL;
	nbr_ops = 0;
	min_nbr_ops = 0;
	max = sort->size * sort->size;
	while (nbr_ops < max && (min_ops && min_nbr_ops >= nbr_ops))
	{
		if (sort->a->next && (sort->a->order == sort->a->next->order + 1))
			ft_do_operation(sort, SA);
		
	}
}
