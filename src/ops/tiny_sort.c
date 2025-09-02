/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:08:42 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/01 20:48:35 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"


t_stack	*ft_fdlowest(t_stack *b, int chunk)
{
	t_stack	*temp;
	t_stack	*lowest;

	temp = b;
	lowest = NULL;
	if (chunk == -1 && b)
	{
		while (temp)
		{
			if (!lowest || temp->index < lowest->index)
				lowest = temp;
			temp = temp->next;
		}
	}
	else if (chunk >= 0 && b)
	{
		while (temp && temp->chunkid == chunk)
		{
			if (!lowest || temp->index < lowest->index)
				lowest = temp;
			temp = temp->next;
		}
	}
	return (lowest);
}

int	ft_tiny_sort_b(t_stack **b)
{
	t_stack	*lowest;
	int		movement;

	movement = 0;
	lowest = ft_fdlowest(*b, -1);
	
	// // HACK:
	// ft_printf("topb: value -> %d\nindex -> %d\nin chunk -> %d\n\n",
	// 	(*b)->value, (*b)->index, (*b)->chunkid);
	// ft_printf("lowest: value -> %d\nindex -> %d\nin chunk -> %d\n\n",
	// 	lowest->value, lowest->index, lowest->chunkid);

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

t_stack	*ft_fdhighest(t_stack *a, int chunk)
{
	t_stack	*temp;
	t_stack	*highest;

	temp = a;
	highest = NULL;
	if (chunk == -1 && a)
	{
		while (temp)
		{
			if (!highest || highest->index < temp->index)
				highest = temp;
			temp = temp->next;
		}
	}
	else if (chunk >= 0 && a)
	{
		while (temp && temp->chunkid == chunk)
		{
			if (!highest || highest->index < temp->index)
				highest = temp;
			temp = temp->next;
		}
	}
	return (highest);
}

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
