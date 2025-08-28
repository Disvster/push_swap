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

#include "../../incs/push_swap.h"

void	ft_stack_rotate(t_stack **top)
{
	t_stack	*first;
	t_stack	*last;

	if (!top || !*top)
		return ;
	first = *top;
	if (!first->next)
		return ;
	last = ft_stacklast(first);
	*top = first->next;
	last->next = first;
	first->next = NULL;
}

void	ft_rotate_both(t_stack **topa, t_stack **topb)
{
	ft_stack_rotate(topa);
	ft_stack_rotate(topb);
}

void	ft_stack_revrotate(t_stack **top)
{
	t_stack	*temp;
	t_stack	*first;
	t_stack	*last;

	if (!top || !*top)
		return ;
	first = *top;
	temp = *top;
	if (!first->next)
		return ;
	while (temp->next->next)
		temp = temp->next;
	last = ft_stacklast(first);
	last->next = first;
	temp->next = NULL;
	*top = last;
}

void	ft_revrotate_both(t_stack **topa, t_stack **topb)
{
	ft_stack_revrotate(topa);
	ft_stack_revrotate(topb);
}
