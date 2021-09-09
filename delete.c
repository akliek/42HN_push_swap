/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:58:30 by akliek            #+#    #+#             */
/*   Updated: 2021/09/06 17:00:10 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stack(t_stack **head)
{
	t_stack	*node;
	t_stack	*tmp;

	node = *head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*head = NULL;
}

void	delete_string_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}
