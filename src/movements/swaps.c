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

#include "../../incs/push_swap.h"

void	ft_stack_swap(t_stack **top, int which_stack)
{
	t_stack	*n1;
	t_stack	*n2;

	if (!top || !*top)
		return ;
	n1 = *top;
	if (n1->next == NULL)
		return ;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	*top = n2;
	ft_printf("s");
	if (which_stack == 0)
		ft_printf("a\n");
	else if (which_stack == 1)
		ft_printf("b\n");
	else if (which_stack == 2)
		ft_printf("s\n");
	else if (which_stack == -1)
		return ;
}

void	ft_swap_both(t_stack **topa, t_stack **topb)
{
	ft_stack_swap(topa, -1);
	ft_stack_swap(topb, 2);
}
