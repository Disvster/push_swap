/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:49:50 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 06:56:58 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	stack_push(t_stack **a, t_stack **b, int which_stack)
{
	t_stack	*noda;

	if (!a || !*a)
		return ;
	noda = *a;
	*a = noda->next;
	noda->next = *b;
	*b = noda;
	if (!which_stack)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
	return ;
}
