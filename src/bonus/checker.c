/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 08:17:20 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 08:56:40 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_op(char *s)
{
	if (!ft_strcmp("sa\n", s))
		return (SA);
	else if (!ft_strcmp("sb\n", s))
		return (SB);
	else if (!ft_strcmp("ss\n", s))
		return (SS);
	else if (!ft_strcmp("pa\n", s))
		return (PA);
	else if (!ft_strcmp("pb\n", s))
		return (PB);
	else if (!ft_strcmp("ra\n", s))
		return (RA);
	else if (!ft_strcmp("rb\n", s))
		return (RB);
	else if (!ft_strcmp("rr\n", s))
		return (RR);
	else if (!ft_strcmp("rra\n", s))
		return (RRA);
	else if (!ft_strcmp("rrb\n", s))
		return (RRB);
	else if (!ft_strcmp("rrr\n", s))
		return (RRR);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_sort	sort;
	t_stack	*a;
	int		size;
	char	*s;
	int		op;

	if (argc < 2)
		return (0);
	a = ft_checked_args(argc - 1, &argv[1], &size);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	ft_init_sort(&sort, a, size);
	s = get_next_line(0);
	op = ft_get_op(s);
	if (op < 0)
		return (ft_clear_stack(&sort.a), write(2, "Error\n", 6), 1);
	while (s)
	{
		free(s);
		s = get_next_line(0);
		op = ft_get_op(s);
		if (op < 0)
			return (ft_clear_stack(&sort.a), write(2, "Error\n", 6), 1);
		ft_do_op(&sort, op);
	}
	if (ft_is_sorted(sort.a) && !sort.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clear_stacks(&sort.a, &sort.b);
}
