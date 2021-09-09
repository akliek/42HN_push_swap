/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akliek <akliek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:24:07 by akliek            #+#    #+#             */
/*   Updated: 2021/09/08 12:57:39 by akliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*============LIST============*/

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/*============UTILS============*/

int		get_last(t_stack *stack);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_position(t_stack *stack, int num);
int		get_bigger_than_prev(t_stack *stack, int prev_edge, int edge);

/*============TOOLS============*/

int		is_sorted(t_stack *a);
int		ft_lstsize(t_stack *lst);
long	ft_atoi(const char *str);
char	**split(char const *s, char c);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int num);

/*============DELETE============*/

void	delete_stack(t_stack **head);
void	delete_string_array(char **s);

/*============VALIDATION============*/

int		is_number(char *s);
int		duplicates(t_stack *a, int n);

/*============OPERATIONS============*/

void	swap(t_stack *stack, char c);
void	rotate(t_stack **stack, t_stack **stack_1, char c);
t_stack	*push(t_stack **stack1, t_stack **stack2, char c);
t_stack	*reverse_rotate(t_stack **stack, char c);

/*============ALGORITHM============*/

void	algorithm(t_stack **a, int len, int chunk_size);

#endif
