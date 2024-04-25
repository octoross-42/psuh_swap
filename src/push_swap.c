/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:28:49 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/23 19:05:05 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_sort(t_sort *sort, t_stack *a, int size)
{
	sort->a = a;
	sort->b = NULL;
	sort->size_a = size;
	sort->size_b = 0;
	sort->min_a = 1;
	sort->min_b = 0;
	sort->max_a = size;
	sort->max_b = 0;
	sort->size = size;
	sort->ops = NULL;
	sort->nbr_ops = 0;
	if (size <= 5)
		sort->nbr_chunks = TINY_NBR_CHUNKS;
	else if (size <= 10)
		sort->nbr_chunks = SMALL_NBR_CHUNKS;
	else if (size <= 150)
		sort->nbr_chunks = MEDIUM_NBR_CHUNKS;
	else
		sort->nbr_chunks = BIG_NBR_CHUNKS;
	sort->size_chunk = sort->size / sort->nbr_chunks;
	sort->add_chunk = sort->size - sort->size_chunk * sort->nbr_chunks;
}

int main(int argc, char **argv)
{
	t_sort	sort;
	t_stack	*a;
	int		size;

	if (argc < 2)
		return (0);
	a = ft_checked_args(argc - 1, &argv[1], &size);
	if (!a)
	{
		if (!PRINT_ERRORS)
			write(1, "Error\n", 6);
		return (1);
	}
	ft_init_sort(&sort, a, size);
	ft_sort(&sort);
	// ft_print_stacks(sort.a, sort.b);
	ft_synthetise_ops(sort.nbr_ops, &sort.ops);
	ft_print_operations(sort.ops);
	ft_clear_stacks(&sort.a, &sort.b);
	// ft_clear_operations(sort.ops);
	return (0);
}

// TODO fix printf