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

void	ft_stack_rotate(t_stack **top, int which_stack)
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
	ft_printf("r");
	if (which_stack == 0)
		ft_printf("a\n");
	else if (which_stack == 1)
		ft_printf("b\n");
	else if (which_stack == 2)
		ft_printf("r\n");
	else if (which_stack == -1)
		return ;
}

void	ft_rotate_both(t_stack **topa, t_stack **topb)
{
	ft_stack_rotate(topa, -1);
	ft_stack_rotate(topb, 2);
}

void	ft_stack_revrotate(t_stack **top, int which_stack)
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
	ft_printf("rr");
	if (which_stack == 0)
		ft_printf("a\n");
	else if (which_stack == 1)
		ft_printf("b\n");
	else if (which_stack == 2)
		ft_printf("r\n");
	else if (which_stack == -1)
		return ;
}

void	ft_revrotate_both(t_stack **topa, t_stack **topb)
{
	ft_stack_revrotate(topa, -1);
	ft_stack_revrotate(topb, 2);
}
