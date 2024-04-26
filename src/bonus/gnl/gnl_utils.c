/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:33:07 by octoross          #+#    #+#             */
/*   Updated: 2024/04/26 08:50:46 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	ft_clear_leftovers(t_list **leftovers)
{
	t_list	*next;
	t_list	*to_free;

	if (!(*leftovers))
		return ;
	next = *leftovers;
	while (next)
	{
		if (next->content)
			free(next->content);
		to_free = next;
		next = next->next;
		free(to_free);
	}
}

void	ft_clean_and_next_lst(t_list **line)
{
	t_list	*to_free;

	if ((*line)->start >= (*line)->len)
	{
		to_free = *line;
		*line = (*line)->next;
		free(to_free->content);
		free(to_free);
	}
}
