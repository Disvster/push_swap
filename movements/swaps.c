/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:07:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/04 20:08:30 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_swap(t_stack *top)
{
	t_stack	*n1;
	t_stack	*n2;

	if (!top || !top->next)
		return (top);
	n1 = top;
	n2 = top->next;
	n1->next = n2->next;
	n2->next = n1;
	top = n1;
	return (top);
}

void	ft_swap_both(t_stack **topa, t_stack **topb)
{
	*topa = ft_stack_swap(*topa);
	*topb = ft_stack_swap(*topb);
	ft_printf("ss\n");
}
