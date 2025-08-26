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

int	ft_check_sort(t_stack *s, long *tab, int asc, int range)
{	// range will either be stack_size if we want to check the whole stack. or chunk size for chunk sort check
	t_stack	*tmp;
	int		bcheck;
	int		i;

	tmp = s;
	i = 0;
	if (asc == 1) // check for ascending order
	{
		while (i < range && tmp && (tmp->index < tmp->next->index))
		{
			tmp = tmp->next;
			i++;
		}
	}
	else if (asc == 0) // check for descending order
	{
		while (i < range && tmp && (tmp->index > tmp->next->index))
		{
			tmp = tmp->next;
			i++;
		}
	}
	bcheck = (i == range && tmp); // 1 if we went through the whole range OK, 0 if not (if there was still node in there;
								 // this can also be in the return statment
	return (bcheck);
}
