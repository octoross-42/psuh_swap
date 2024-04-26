/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 02:38:01 by nesuvya           #+#    #+#             */
/*   Updated: 2024/04/26 05:21:11 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_order(int new, t_mkstack *aux, int size)
{
	t_stack	*next;
	int		order;

	if (new > aux->max)
	{
		aux->max = new;
		return (size + 1);
	}
	if (new < aux->max)
	{
		order = 1;
		next = aux->stack;
		while (next)
		{
			if (next->n == new)
				return (0);
			if (next->n > new)
				(next->order)++;
			else
				order ++;
			next = next->next;
		}
		return (order);
	}
	return (0);
}

void	ft_init_parsing(t_mkstack *aux, int *size)
{
	aux->stack = NULL;
	aux->next = NULL;
	aux->i = 0;
	*size = 0;
}

void	ft_no_split(char **splited, t_mkstack *aux)
{
	if (splited)
		free(splited);
	if (PRINT_ERRORS && !splited)
		ft_printf(ERR_MALLOC);
	else if (PRINT_ERRORS)
		ft_printf(ERR_NO_ARG);
	ft_clear_stack(&aux->stack);
}

t_stack	*ft_checked_args(int argc, char **argv, int *size)
{
	char		**splited;
	t_mkstack	aux;

	ft_init_parsing(&aux, size);
	while (aux.i < argc)
	{
		splited = ft_split(argv[aux.i], " \n\t\n\v\r\f");
		if (!splited || !splited[0])
			return (ft_no_split(splited, &aux), NULL);
		aux.j = 0;
		while (splited[aux.j])
		{
			if (!ft_add_new_stack(splited[aux.j], &aux, size))
				return (ft_free_until((void **)splited, aux.j, -1),
					ft_clear_stack(&aux.stack), NULL);
			ft_go_to_next_stack(aux.stack, &aux.next);
			free(splited[aux.j]);
			aux.j ++;
		}
		free(splited);
		aux.i ++;
	}
	return (aux.stack->previous = aux.next, aux.stack);
}
