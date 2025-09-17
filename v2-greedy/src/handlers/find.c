/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:50:53 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/08 22:47:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*find_lowest(t_stack *s)
{
	t_stack	*lowest;
	t_stack	*temp;

	temp = s;
	lowest = NULL;
	if (s)
	{
		while (temp)
		{
			if (!lowest || temp->index < lowest->index)
				lowest = temp;
			temp = temp->next;
		}
	}
	return (lowest);
}

t_stack	*find_nextlowest(t_stack *s, t_stack *ref)
{
	t_stack	*temp;
	t_stack	*nlowest;
	int		id;

	temp = s;
	id = ref->index;
	nlowest = NULL;
	if (s && id >= 0)
	{
		while (temp)
		{
			if (temp->index < id && (!nlowest || temp->index > nlowest->index))
				nlowest = temp;
			temp = temp->next;
		}
		if (!nlowest)
			return (ref);
	}
	return (nlowest);
}

t_stack	*find_highest(t_stack *s)
{
	t_stack	*highest;
	t_stack	*temp;

	temp = s;
	highest = NULL;
	if (s)
	{
		while (temp)
		{
			if (!highest || temp->index > highest->index)
				highest = temp;
			temp = temp->next;
		}
	}
	return (highest);
}

t_stack	*find_nexthighest(t_stack *s, t_stack *ref)
{
	t_stack	*temp;
	t_stack	*nhighest;
	int		id;

	temp = s;
	id = ref->index;
	nhighest = NULL;
	if (s && id >= 0)
	{
		while (temp)
		{
			if (temp->index > id
				&& (!nhighest || temp->index < nhighest->index))
				nhighest = temp;
			temp = temp->next;
		}
		if (!nhighest)
			return (ref);
	}
	return (nhighest);
}

t_stack	*node_search(t_stack *s, int nb)
{
	while (s)
	{
		if (s->index == nb)
			return (s);
		s = s->next;
	}
	return (NULL);
}
