/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:24:16 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/17 20:26:14 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	double_rotations(t_stack **a, t_stack **b, t_stack *targ)
{
	int	c;

	c = targ->cost;
	while (*a != targ && *b != targ->target)
	{
		if (targ->mov > 0 && targ->target->mov > 0)
			stack_rr(a, b);
		else if (targ->mov < 0 && targ->target->mov < 0)
			stack_rrr(a, b);
		c--;
	}
	targ->cost = c;
}

void	single_rotations(t_stack **a, t_stack **b, t_stack *targa, char w)
{
	int	c;

	if (*a == targa && *b == targa->target)
		return ;
	c = targa->cost;
	while (*a != targa)
	{
		if (targa->mov > 0)
			stack_rotate(a, w);
		else if (targa->mov < 0)
			stack_revrotate(a, w);
		c--;
	}
	while ((*b)->index != targa->target->index)
	{
		if (targa->target->mov > 0)
			stack_rotate(b, !w);
		else if (targa->target->mov < 0)
			stack_revrotate(b, !w);
		c--;
	}
	targa->cost = c;
}
