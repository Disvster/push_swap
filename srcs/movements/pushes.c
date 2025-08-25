/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:49:50 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/04 19:52:26 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	**ft_stack_push(t_stack **topa, t_stack **topb)
{
	t_stack	*tempa;
	t_stack	*tempb;

	if (!topb)
		return (topa);
	tempb = *topb;
	if (!topa)
	{
		tempa = stack_newnode(tempb->value, tempb->index, tempb->chunkid);
		topa = &tempa;
		*topb = tempb->next;
		free(tempb);
		tempb = NULL;
		return (topa);
	}
	tempa = *topa;
	*topb = tempb->next;
	tempb->next = tempa;
	*topa = tempb;
	return (topa);
}
