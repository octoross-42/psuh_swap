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
	if (s->size == 3)
		return ;
	else
	{
		ft_push_to_b(s);
		ft_push_back_to_a(s);
	}
}
