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

#include "../../incs/push_swap.h"

// NOTE: function below is depecrecated
t_stack	**ft_notstack_push(t_stack **topa, t_stack **topb)
{
	t_stack	*tempa;
	t_stack	*tempb;

	if (!topb)
		return (topa);
	tempb = *topb;
	if (!topa)
	{
		tempa = ft_stack_newnode(tempb->value, tempb->index, tempb->chunkid);
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

void	ft_stack_push(t_stack **a, t_stack **b)
{
	t_stack	*noda;

	if (!a || !*a)
		return ;
	noda = *a;
	*a = noda->next;
	noda->next = *b;
	*b = noda;
	return ;
}
