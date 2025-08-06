/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:04 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/04 20:08:37 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_newnode(int value, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	stack_add_front(t_stack **stack, t_stack *new_nd)
{
	new_nd->next = *stack;
	*stack = new_nd;
}

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!lst)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*lst = NULL;
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
