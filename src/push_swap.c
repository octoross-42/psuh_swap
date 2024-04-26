/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:28:49 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/26 08:52:11 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
			write(2, "Error\n", 6);
		return (1);
	}
	ft_init_sort(&sort, a, size);
	ft_sort(&sort);
	ft_synthetise_ops(&sort.ops);
	ft_print_operations(sort.ops);
	ft_clear_stacks(&sort.a, &sort.b);
	return (0);
}
