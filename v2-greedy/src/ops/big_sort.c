/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 21:09:39 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/17 21:15:39 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*get_lesscost(t_stack *s)
{
	t_stack	*target;
	t_stack	*temp;

	temp = s;
	target = NULL;
	while (temp)
	{
		temp->cost = 0;
		if (temp->mov > 0 && temp->target->mov > 0)
			temp->cost = ft_max(temp->mov, temp->target->mov);
		else if (temp->mov < 0 && temp->target->mov < 0)
			temp->cost = ft_max(ft_abs(temp->mov), ft_abs(temp->target->mov));
		else if (temp->mov <= 0 && temp->target->mov > 0)
			temp->cost = ft_abs(temp->mov) + temp->target->mov;
		else if (temp->mov >= 0 && temp->target->mov < 0)
			temp->cost = temp->mov + ft_abs(temp->target->mov);
		else if (temp->mov < 0 && temp->target->mov >= 0)
			temp->cost = ft_abs(temp->mov) + temp->target->mov;
		else if (temp->mov > 0 && temp->target->mov <= 0)
			temp->cost = temp->mov + ft_abs(temp->target->mov);
		if (!target || (temp->cost < target->cost))
			target = temp;
		temp = temp->next;
	}
	return (target);
}

void	set_target(t_stack *a, t_stack *b, char w)
{
	t_stack	*target;
	t_stack	*temp;

	target = NULL;
	temp = a;
	if (w == 'b')
		temp = b;
	while (temp)
	{
		if (w == 'a')
		{
			target = find_nextlowest(b, temp);
			if (temp == find_nextlowest(b, temp))
				target = find_highest(b);
		}
		else if (w == 'b')
		{
			target = find_nexthighest(a, temp);
			if (temp == find_nextlowest(b, temp))
				target = find_highest(a);
		}
		temp->target = target;
		temp = temp->next;
	}
}

void	set_mov(t_stack *s)
{
	t_stack	*temp;
	int		i;
	int		size;

	if (!s)
		return ;
	temp = s;
	size = ft_stack_size(s);
	i = 0;
	while (temp)
	{
		if (i <= size / 2)
			temp->mov = i;
		else
			temp->mov = i - size;
		temp = temp->next;
		i++;
	}
}

void	targets_to_top(t_stack **a, t_stack **b)
{
	t_stack	*targa;

	set_mov(*a);
	set_mov(*b);
	set_target(*a, *b, 'a');
	targa = get_lesscost(*a);
	while (targa->cost > 0)
	{
		if (*a == targa && *b == targa->target)
			break ;
		if ((targa->mov > 0 && targa->target->mov > 0)
			|| (targa->mov < 0 && targa->target->mov < 0))
			double_rotations(a, b, targa);
		single_rotations(a, b, targa, 0);
	}
}

void	nodes_to_a(t_stack **a, t_stack **b)
{
	t_stack	*targb;
	int		c;

	c = -1;
	set_mov(*b);
	targb = find_highest(*b);
	while (*b != targb)
	{
		if (targb->mov > 0)
			stack_rotate(b, 1);
		if (targb->mov < 0)
			stack_revrotate(b, 1);
	}
	while (*b)
		stack_push(b, a, 1);
	return ;
}
	/* TODO: reverse the sorting for logic to push nodes to A above
	 * draft:

	while (++c < 3)
		stack_push(b, a, 1);
	sort_three_a(a);
	while (*b)
	{
		mini_print_stack(a, b);// HACK:
		set_mov(*a);
		set_mov(*b);
		set_target(*a, *b, 'b');
		targb = get_lesscost(*b);
		while (targb->cost > 0)
		{
			if (*a == targb && *b == targb->target)
				break ;
			if ((targb->mov > 0 && targb->target->mov > 0)
				|| (targb->mov < 0 && targb->target->mov < 0))
				double_rotations(a, b, targb);
			single_rotations(b, a, targb, 1);
		}
		stack_push(b, a, 1);
	}*/
