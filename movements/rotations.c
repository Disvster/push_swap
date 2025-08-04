/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:12:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/04 20:08:34 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	**ft_stack_rotate(t_stack **top)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack *last;

	first = *top;
	if (!first->next)
		return (top);
	last = ft_stacklast(first);
	last->next = first;
	*top = first->next;
	first->next = NULL;
	return (top);
}

void	ft_rotate_both(t_stack **topa, t_stack **topb)
{
	topa = ft_stack_rotate(topa);
	topb = ft_stack_rotate(topb);
	ft_printf("rr\n");
}

t_stack	**ft_stack_revrotate(t_stack **top)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack *last;

	first = *top;
	if (!first->next)
		return (top);
	return (top);
}
