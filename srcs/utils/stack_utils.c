/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:04 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/25 15:00:32 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*stack_newnode(int value, int index, int chunk_size)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->chunkid = index / chunk_size;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_front(t_stack **stack, t_stack *new_nd)
{
	new_nd->next = *stack;
	*stack = new_nd;
}

void	ft_stack_clear(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!lst)
		return ;
	node = lst;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	lst = NULL;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_check_sort(t_stack *s, long *tab, int order)
{
	// this func should now if I want to check the full order or just
	// a specific range in the long array
	int	bcheck;
	int	i;

	bcheck = 0;
	i = 0;
	// pseudo code
	if (order == 1) // check for ascending order

	else if (order == 0) // check for descending order
	{
			if (/*check in specific range */)
			else // check the whole stack
	}	
	return (bcheck);
}
