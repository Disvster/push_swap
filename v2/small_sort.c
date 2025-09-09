/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:43:00 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/08 22:46:47 by manmaria         ###   ########.fr       */
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

void	sort_five_a(t_stack **a, t_stack **b)
{
	t_stack	*high;
	t_stack	*befhigh;

	high = find_highest(*a);
	befhigh = find_nextlowest(*a, high);
}


