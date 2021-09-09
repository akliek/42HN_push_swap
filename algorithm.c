/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:08:10 by akliek            #+#    #+#             */
/*   Updated: 2021/09/07 10:43:54 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	find_first_smaller(t_stack *stack, int num)
{
	int	position;

	position = 1;
	while (stack)
	{
		if (stack->num <= num)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}

static int	get_edge(t_stack *a, int chunk_size)
{
	int		edge;
	int		prev_edge;
	t_stack	*tmp;

	edge = get_min(a);
	while (--chunk_size > 0)
	{
		tmp = a;
		prev_edge = edge;
		edge = get_bigger_than_prev(tmp, prev_edge, edge);
		while (tmp)
		{
			if (tmp->num > prev_edge && tmp->num < edge)
				edge = tmp->num;
			tmp = tmp->next;
		}
	}
	return (edge);
}

static void	push_back(t_stack **a, t_stack **b, int len)
{
	int	max;

	while (len > 0)
	{
		max = get_max(*b);
		if (get_position(*b, max) > len / 2)
			while ((*b)->num != max)
				*b = reverse_rotate(b, 'b');
		else
			while ((*b)->num != max)
				rotate(b, a, 'b');
		*a = push(a, b, 'a');
		len--;
	}
}

void	push_chunk(t_stack **a, t_stack **b, int len, int edge)
{
	if (find_first_smaller(*a, edge) > len / 2)
	{
		while ((*a)->num > edge)
		{
			*a = reverse_rotate(a, 'a');
			if ((*b) && (*b)->num < get_last(*b))
			{
				*b = reverse_rotate(b, 'r');
				write(1, "rrr\n", 4);
			}
			else
				write(1, "rra\n", 4);
		}
	}
	else
	{
		while ((*a)->num > edge)
		{
			if ((*b) && (*b)->next && (*b)->num < (*b)->next->num)
				rotate(a, b, 'r');
			else
				rotate(a, b, 'a');
		}
	}
	*b = push(b, a, 'b');
}

void	algorithm(t_stack **a, int len, int chunk_size)
{
	int		tmp;
	int		edge;
	t_stack	*b;

	b = NULL;
	while (len > 0)
	{
		tmp = chunk_size;
		if (len < tmp)
		{
			while (len-- > 0)
				b = push(&b, a, 'b');
			break ;
		}
		edge = get_edge(*a, tmp);
		while (tmp-- > 0)
			push_chunk(a, &b, len, edge);
		len -= chunk_size;
	}
	push_back(a, &b, ft_lstsize(b));
}
