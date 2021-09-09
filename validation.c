/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:53:42 by akliek            #+#    #+#             */
/*   Updated: 2021/09/08 12:57:31 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	if (!s)
		return (0);
	if (*s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < 48 || *s > 57)
			return (0);
		s++;
	}
	return (1);
}

int	duplicates(t_stack *a, int n)
{
	while (a)
	{
		if (a->num == n)
			return (0);
		a = a->next;
	}
	return (1);
}
