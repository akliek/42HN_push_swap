/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:46:25 by akliek            #+#    #+#             */
/*   Updated: 2021/09/08 17:14:52 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_splits(int size)
{
	int	chunk_size;

	chunk_size = 0;
	if (size <= 100)
	{
		while (size > 0)
		{
			chunk_size += 1;
			size -= 18;
		}
	}
	else
	{
		chunk_size = 5;
		while (size >= 150)
		{
			chunk_size += 2;
			size -= 150;
		}
	}
	return (chunk_size);
}

static void	sort_small(t_stack **a, int size)
{
	if (size == 2)
		swap(*a, 'a');
	else if (size == 3)
	{
		if (get_position(*a, get_max(*a)) == 1)
		{
			rotate(a, NULL, 'a');
			if ((*a)->num > (*a)->next->num)
				swap(*a, 'a');
		}
		else if (get_position(*a, get_max(*a)) == 2)
		{
			*a = reverse_rotate(a, 'a');
			if ((*a)->num > (*a)->next->num)
				swap(*a, 'a');
		}
		else if (get_position(*a, get_max(*a)) == 3
			&& (*a)->num > (*a)->next->num)
			swap(*a, 'a');
	}
}

static void	sort_more(t_stack **a, int size)
{
	int		min;
	t_stack	*b;

	b = NULL;
	while (size > 3 && (*a)->next->next->next)
	{
		min = get_min(*a);
		if (get_position(*a, min) > size / 2)
			while ((*a)->num != min)
				*a = reverse_rotate(a, 'a');
		else
			while ((*a)->num != min)
				rotate(a, &b, 'a');
		b = push(&b, a, 'b');
	}
	sort_small(a, 3);
	while (b)
		*a = push(a, &b, 'a');
}

static int	parse(t_stack **a, char *argv, int *argc, int i)
{
	long	n;
	char	**num;

	num = split(argv, ' ');
	if (!*num)
	{
		delete_string_array(num);
		return (0);
	}
	while (num[i])
	{
		n = ft_atoi(num[i]);
		if (!is_number(num[i]) || n > INT_MAX || n < INT_MIN
			|| !duplicates(*a, n))
		{
			delete_string_array(num);
			return (0);
		}
		ft_lstadd_back(a, ft_lstnew(n));
		i++;
	}
	delete_string_array(num);
	*argc += i - 1;
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	a = NULL;
	i = 0;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	while (argv[++i])
	{
		if (!parse(&a, argv[i], &argc, 0))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
	}
	if (is_sorted(a))
		return (0);
	else if (argc <= 6)
		sort_more(&a, argc - 1);
	else
		algorithm(&a, ft_lstsize(a), (argc - 1) / get_splits(argc - 1));
	delete_stack(&a);
	return (0);
}
