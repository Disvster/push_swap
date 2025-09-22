/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:12:10 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 06:59:50 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	stack_rotate(t_stack **top, int which_stack)
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
	if (which_stack == 0)
		ft_printf("ra\n");
	else if (which_stack == 1)
		ft_printf("rb\n");
	else if (which_stack == 2)
		ft_printf("rr\n");
	else if (which_stack == -1)
		return ;
}

void	stack_rr(t_stack **topa, t_stack **topb)
{
	stack_rotate(topa, -1);
	stack_rotate(topb, 2);
}

void	stack_revrotate(t_stack **top, int which_stack)
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
	if (which_stack == 0)
		ft_printf("rra\n");
	else if (which_stack == 1)
		ft_printf("rrb\n");
	else if (which_stack == 2)
		ft_printf("rrr\n");
	else if (which_stack == -1)
		return ;
}

void	stack_rrr(t_stack **topa, t_stack **topb)
{
	stack_revrotate(topa, -1);
	stack_revrotate(topb, 2);
}
