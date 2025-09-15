/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:43:00 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 06:38:24 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **a)
{
	t_stack	*highest;

	highest = find_highest(*a);
	if (*a == highest)
		stack_rotate(a, 0);
	else if ((*a)->next == highest)
		stack_revrotate(a, 0);
	if ((*a)->index > (*a)->next->index)
		stack_swap(a, 0);
}

void	sort_three_b(t_stack **b)
{
	t_stack	*lowest;

	lowest = find_lowest(*b);
	if (*b == lowest)
		stack_rotate(b, 1);
	else if ((*b)->next == lowest)
		stack_revrotate(b, 1);
	if ((*b)->index < (*b)->next->index)
		stack_swap(b, 1);
}

char	node_idsearch(t_stack *a, int nb)
{
	while (a)
	{
		if (a->index == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	sort_five_a(t_stack **a, t_stack **b)
{
	while (node_idsearch(*a, 0) || node_idsearch(*a, 1))
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			stack_push(a, b, 0);
		else
			stack_rotate(a, 0);
	}
	sort_three_a(a);
	if ((*b)->index == 0 && (*b)->next->index == 1)
		stack_swap(b, 1);
	stack_push(b, a, 1);
	if (*b)
		stack_push(b, a, 1);
}
// void	sort_five_a(t_stack **a, t_stack **b)
// {
// 	t_stack	*high;
// 	t_stack	*befhigh;
//
// 	high = find_highest(*a);
// 	befhigh = find_nextlowest(*a, high);
// 	while (*a != high && *a != high)
//
// }
