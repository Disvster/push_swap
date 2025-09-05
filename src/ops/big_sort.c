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
	// how many times either ra or rra will be stored in
	// target->cost
	t_stack *b_high;
	// int		valtobe;
	int		rotb;
	int	tar_cost = target->cost;

	if (!*b)
	{
		while (tar_cost >= 0 && *a != target)
		{
			if (rota == 1)//ra
				ft_stack_rotate(a, 0);
			else if (rota == 0)//rra
				ft_stack_revrotate(a, 0);
			tar_cost--;
		}
		return ;
	}
	b_high = ft_fdhighest(*b, -1);//target->chunkid);
	// b_high_cost = b_high->cost;// NOTE: need to save this so I know how many rb or rrb(based on rotb) I need to put it at the top again

	// the while loop below is wrong, I need to search for the bigger number that is not the highest
	// not the highest AFTER the highest
	if (target->index < b_high->index)
		b_high = ft_fdhighest(*b, target->index);
	
	if (ft_stack_size(*b) > 1)
		rotb = ft_node_cost(*b, &b_high);
	
	// agora eu vou meter o b_high no topo de B
	// depois vejo se i > 0 entao tenho que voltar a procurar pelo actual HIGHEST
	// e mete lo no topo da B; i++ vai ser o offset de index entre o target e o b_high
	while (tar_cost-- && *b != b_high && rota == rotb)
	{
		// eu sei que A quer rodar target->cost numero de vezes
		// B quer rodar ate b_highest ser igual ao topo da B
		if (rota == 1)// rr
			ft_rotate_both(a, b);
		else if (rota == 0)//rrr
			ft_revrotate_both(a, b);
	}
	while (tar_cost >= 0)
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
			ft_stack_rotate(b, 0);
		else if (rotb == 0)//rrb
			ft_stack_revrotate(b, 0);
	}
	if (tar_cost == -1 && *b == b_high)
		ft_stack_push(a, b, 0);
	b_high = ft_fdhighest(*b, -1);
	if (b_high != *b)
		rotb = ft_node_cost(*b, &b_high);
	while (*b != b_high)
	{
		if (rotb == 1)//rb
			ft_stack_rotate(b, 0);
		else if (rotb == 0)//rrb
			ft_stack_revrotate(b, 0);
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
