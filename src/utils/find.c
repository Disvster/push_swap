/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:35:14 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/02 15:35:59 by manmaria         ###   ########.fr       */
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
