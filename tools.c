/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:09:24 by akliek            #+#    #+#             */
/*   Updated: 2021/09/06 16:59:00 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack	*ft_lstnew(int num)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->num = num;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*res;

	res = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (res->next)
		res = res->next;
	res->next = new;
	return ;
}

int	is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->next && a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (sign * res);
}
