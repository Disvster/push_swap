/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:08:42 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/02 16:56:08 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_tiny_sort_b(t_stack **b)
{
	t_stack	*lowest;
	int		movement;

	movement = 0;
	lowest = ft_fdlowest(*b, -1);
	
	if (*b == lowest)
		// ft_stack_rotate(b, 1);
		movement += 1;// I want to rotate b
	else if ((*b)->next == lowest)
		// ft_stack_revrotate(b, 1);
		movement += -1;// I want to rev rotate b
	if ((*b)->index < (*b)->next->index)
		ft_stack_swap(b, 1);
	return (movement);
}
	// HACK: tiny_sort_b debug
	// ft_printf("topb: value -> %d\nindex -> %d\nin chunk -> %d\n\n",
	// 	(*b)->value, (*b)->index, (*b)->chunkid);
	// ft_printf("lowest: value -> %d\nindex -> %d\nin chunk -> %d\n\n",
	// 	lowest->value, lowest->index, lowest->chunkid);

int	ft_tiny_sort_a(t_stack **a)
{
	t_stack	*highest;
	int		movement;

	movement = 0;
	highest = ft_fdhighest(*a, -1);
	if (*a == highest)
		ft_stack_rotate(a, 0);
		// movement += 1;// I want to rotate a
	else if ((*a)->next == highest)
		ft_stack_revrotate(a, 0);
		// movement += -1;// I want to rev rotate a
	if ((*a)->index > (*a)->next->index)
		ft_stack_swap(a, 0);
	return (movement);
}

int	ft_node_cost(t_stack *top, t_stack *target)
{
	int		ctop;
	int		cbot;
	t_stack	*bot;

	if (!top)
		return (0);
	ctop = 0;
	cbot = (ft_stack_size(top) / 2) + 1;
	bot = ft_stack_middle(top);
	if (bot->next && bot != target)
		bot = bot->next;
	while (top)
	{
		if (top == target || top->next == bot)
			break ;
		top = top->next;
		ctop += 1;
	}
	while (bot)
	{
		if (bot == target)
			break ;
		bot = bot->next;
		cbot--;
	}
	top->cost = ctop;
	if (bot)
		bot->cost = cbot;
	return (ctop <= cbot);
}

void	ft_sort_five_a(t_stack **a, t_stack **b)
{
	int		size;
	t_stack *lowest;

	while (ft_stack_size(*a) > 3)
	{
		lowest = ft_fdlowest(*a, -1);
		if ((*a) == lowest)
			ft_stack_push(a, b, 0);
		else if (ft_node_cost(*a, lowest))
			ft_stack_rotate(a, 0);
		else
			ft_stack_revrotate(a, 0);
		if ((*a) == lowest)
			ft_stack_push(a, b, 0);
	}
	ft_tiny_sort_a(a);
	size = ft_stack_size(*b);
	while (size--)
		ft_stack_push(b, a, 1);
}
