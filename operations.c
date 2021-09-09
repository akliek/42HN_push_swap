/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:05:29 by akliek            #+#    #+#             */
/*   Updated: 2021/09/06 16:57:51 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	last(t_stack *stack, int num)
{
	t_stack	*last;

	last = ft_lstnew(num);
	while (stack->next)
		stack = stack->next;
	stack->next = last;
}

void	swap(t_stack *stack, char c)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

t_stack	*push(t_stack **stack1, t_stack **stack2, char c)
{
	t_stack	*next;
	t_stack	*head;

	if (!*stack2)
		return (*stack1);
	head = ft_lstnew((*stack2)->num);
	head->next = *stack1;
	next = (*stack2)->next;
	free(*stack2);
	*stack2 = next;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return (head);
}

void	rotate(t_stack **stack, t_stack **stack_1, char c)
{
	int		num;

	num = (*stack)->num;
	free(*stack);
	*stack = (*stack)->next;
	last(*stack, num);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	else if (c == 'r')
	{
		write(1, "rr\n", 3);
		rotate(stack_1, stack, ' ');
	}
}

t_stack	*reverse_rotate(t_stack **stack, char c)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->next = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	new->num = (*stack)->next->num;
	free((*stack)->next);
	(*stack)->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (new);
}
