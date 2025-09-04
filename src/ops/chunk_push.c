/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:28:53 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/02 16:57:45 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"
#include "../../incs/testing.h"

char	chunk_search(t_stack *a, int chunk)
{
	while (a)
	{
		if (a->chunkid == chunk)
			return (1);
		a = a->next;
	}
	return (0);
}
// TODO: a stack B ta a ser ordenada em ordem crescente which is not what I want
//		 e o ultimo node ta a dar segfault no ft_chunk_cost
void	ft_chunk_push(t_stack **a, t_stack **b, int s_size)
{
	t_chunk	chunki;
	int		i;

	i = 0;
	chunki = ft_chunkinit(s_size);
	while (/*s_size > chunki.size &&*/ i < chunki.count - 1)
	{
		mini_print_stacks(a, b);
		ft_chunk_prep(a, b, i);
		if (chunk_search(*a, i))
		{
			// I cannot push here bcs push was already done in chunk_prep
			// ft_stack_push(a, b, 0);
			ft_chunk_prep(a, b, i);
			s_size--;
		}
		else
			i++;
			// mini_print_stacks(a, b);
	}
}
//			NOTE: this was inside the else statement:
			// if (ft_stack_size(*b) == 3)
			// 	ft_tiny_sort_b(b);
			// else if (ft_stack_size(*b) <= 2)
			// 	if (!ft_checksort(*b, 1, ft_stack_size(*b)))
			// 		ft_stack_swap(b, 1);
// NOTE: this was below the while above:
// mini_print_stacks(a, b);
// if (s_size == 3)
// 	ft_tiny_sort_a(a);
// else if (s_size <= 2)
// 	if (!ft_checksort(*a, 0, 2))
// 		ft_stack_swap(a, 0);
// if (ft_stack_size(*b) == 3)
// 	ft_tiny_sort_b(b);
// else if (ft_stack_size(*b) <= 2)
// 	if (!ft_checksort(*b, 1, ft_stack_size(*b)))
// 		ft_stack_swap(b, 1);
// mini_print_stacks(a, b);
