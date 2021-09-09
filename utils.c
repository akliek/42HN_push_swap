/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 15:24:05 by akliek            #+#    #+#             */
/*   Updated: 2021/09/06 11:55:12 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger_than_prev(t_stack *stack, int prev_edge, int edge)
{
	while (stack)
	{
		if (stack->num > prev_edge)
		{
			edge = stack->num;
			break ;
		}
		stack = stack->next;
	}
	return (edge);
}

int	get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	get_position(t_stack *stack, int num)
{
	int	position;

	position = 1;
	while (stack)
	{
		if (stack->num == num)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}
