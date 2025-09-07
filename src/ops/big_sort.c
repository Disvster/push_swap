/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:22:27 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/03 22:37:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"
#include "../../incs/testing.h"

void	ft_big_sort(t_stack **a, t_stack **b, t_stack *target, int rota)
{
	// if rot == 1 then I want to rotate A
	// if rot == 0 then I want to reverse rotate A
	t_stack *b_high;
	int		rotb;
	int	tar_cost;

	tar_cost = target->cost;
	if (!*b)
	{
		while (*a != target)
		{
			if (rota == 1)//ra
				ft_stack_rotate(a, 0);
			else if (rota == 0)//rra
				ft_stack_revrotate(a, 0);
			tar_cost--;
		}
		ft_stack_push(a, b, 0);
		return ;
	}
	b_high = find_highest(*b, -1);

	if (target->index < b_high->index && ft_stack_size(*b) > 1)
	{
		if (target->index == 0)
			b_high = find_highest(*b, 0);
		else
			b_high = find_lowest(*b, target->index);
		if (!b_high)
			b_high = find_highest(*b, target->index);
	}

	if (ft_stack_size(*b) > 1)
		rotb = ft_node_cost(*b, &b_high);
	
	while ((*a) != target && *b != b_high && rota == rotb)
	{
		// eu sei que A quer rodar target->cost numero de vezes
		// B quer rodar ate b_highest ser igual ao topo da B
		if (rota == 1)// rr
			ft_rotate_both(a, b);
		else if (rota == 0)//rrr
			ft_revrotate_both(a, b);
		tar_cost--;
	}
	while ((*a) != target)
	{
		if (rota == 1)//ra
			ft_stack_rotate(a, 0);
		else if (rota == 0)//rra
			ft_stack_revrotate(a, 0);
		tar_cost--;
	}
	while (*b != b_high)
	{
		if (rotb == 1)//rb
			ft_stack_rotate(b, 1);
		else if (rotb == 0)//rrb
			ft_stack_revrotate(b, 1);
	}
	// if (tar_cost == 0 && *b == b_high)
		ft_stack_push(a, b, 0);
	b_high = find_highest(*b, -1);
	if (b_high != *b)
	{
		if (ft_stack_size(*b) <= 3)
		{
			ft_tiny_sort_b(b);
			return ;
		}
		else if (ft_stack_size(*b) <= 5)
		{
			ft_sort_five_b(a, b);
			return ;
		}
		else
			rotb = ft_node_cost(*b, &b_high);
	}
	while (*b != b_high)
	{
		if (rotb == 1)//rb
			ft_stack_rotate(b, 1);
		else if (rotb == 0)//rrb
			ft_stack_revrotate(b, 1);
	}
	mini_print_stacks(a, b);
}
// t_stack	*ft_find_closest_bigger(t_stack *stack, int target_index)
// {
// 	t_stack	*closest = NULL;
//
// 	while (stack)
// 	{
// 		if (stack->index > target_index)
// 		{
// 			if (!closest || stack->index < closest->index)
// 				closest = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (closest);
// }
