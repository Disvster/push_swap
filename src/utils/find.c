/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:35:14 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/03 21:43:01 by manmaria         ###   ########.fr       */
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

t_stack	*ft_fdhighest(t_stack *stack, int chunk)
{
	t_stack	*highest;

	highest = NULL;
	if (chunk == -1 && stack)
	{
		while (stack)
		{
			if (!highest || highest->index < stack->index)
				highest = stack;
			stack = stack->next;
		}
	}
	else if (chunk >= 0 && stack)
	{
		while (stack)
		{
			if (stack->index > chunk)
				if (!highest || stack->index < highest->index)
					highest = stack;
			stack = stack->next;
		}
	}
	else
		return (NULL);
	return (highest);
}
