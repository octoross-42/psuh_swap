#include "push_swap.h"

void	ft_get_closer_of_chunk_n_in_b(t_sort *sort, int chunk_min, int chunk_max, int next_chunk_min, int next_chunk_max)
{
	static	int top_a = 0;
	static	int bottom_a = 0;
	t_stack	*next;

	if (chunk_min <= sort->a->order && sort->a->order <= chunk_max)
	{
		ft_do_operation(sort, PB);
		return ;
	}
	next = sort->a->next;
	if (!top_a && (bottom_a != -1))
	{
		top_a = 1;
		while (next && top_a <= sort->size_a / 2)
		{
			if (next->order >= chunk_min && next->order <= chunk_max)
				break ;
			top_a ++;
			next = next->next;
		}
		if (next->order < chunk_min || next->order > chunk_max)
			top_a = -1;
	}
	next = sort->a->previous;
	if (!bottom_a && (bottom_a != -1))
	{
		bottom_a = 1;
		while (next && bottom_a <= sort->size_a / 2)
		{
			if (next->order >= chunk_min && next->order <= chunk_max)
				break ;
			bottom_a ++;
			next = next->previous;
		}
		if (next->order < chunk_min || next->order > chunk_max)
			bottom_a = -1;
	}
	printf("top : %d, bottom : %d\n", top_a, bottom_a);
	if (bottom_a == -1 || (top_a > 0 && top_a < bottom_a))
	{
		while (sort->a->order < chunk_min || sort->a->order > chunk_max)
		{
			if (sort->a->order <= next_chunk_max && sort->a->order >= next_chunk_min)
			{
				
				printf("min : %d, max : %d nextmin %d nextmax %d, order %d\n", chunk_min, chunk_max, next_chunk_min, next_chunk_max, sort->a->order);
				ft_do_operation(sort, PB);
			}
			else
			{
				ft_do_operation(sort, RA);
				if (bottom_a > 0)
					bottom_a ++;
			}
		}
		top_a = 0;
	}
	else
	{
		while (sort->a->order < chunk_min || sort->a->order > chunk_max)
		{
			if (sort->a->order <= next_chunk_max && sort->a->order >= next_chunk_min)
			{
				
				printf("min : %d, max : %d nextmin %d nextmax %d, order %d\n", chunk_min, chunk_max, next_chunk_min, next_chunk_max, sort->a->order);
				ft_do_operation(sort, PB);
				if (top_a > 0)
					top_a --;
			}
			else
			{
				ft_do_operation(sort, RRA);
				if (top_a > 0)
					top_a ++;
			}
		}
		bottom_a = 0;
	}
	ft_do_operation(sort, PB);
	if (sort->b->next && sort->b->next->order > chunk_max)
		ft_do_operation(sort, RB);
}

void	ft_push_to_b(t_sort *sort)
{
	int	i;
	int	chunk;
	int	min_chunk;
	int	max_chunk;
	int	min_next_chunk;
	int	max_next_chunk;
	int	j;

	i = 1;
	chunk = 0;
	while (chunk < sort->nbr_chunks)
	{
		min_chunk = i;
		max_chunk = i - 1 + sort->size_chunk + (chunk >= (sort->nbr_chunks - sort->add_chunk));
		min_next_chunk = max_chunk + 1;
		max_next_chunk = min_next_chunk + sort->size_chunk - 1 + ((chunk + 1) >= (sort->nbr_chunks - sort->add_chunk));
		ft_print_stacks(sort->a, sort->b);
		printf("min %d max %d min next %d max next %d\n", min_chunk, max_chunk, min_next_chunk, max_next_chunk);
		j = min_chunk;
		while (j <= max_chunk)
		{
			ft_get_closer_of_chunk_n_in_b(sort, min_chunk, max_chunk, min_next_chunk, max_next_chunk);
			j ++;
			i ++;
		}
		chunk ++; 
	}
}
