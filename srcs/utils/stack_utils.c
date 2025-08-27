/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:04 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/27 16:57:47 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*ft_stack_newnode(int value, int index, int chunk_size)
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

void	ft_stack_addfront(t_stack **stack, t_stack *new_nd) // NOTE: not using atm
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

char	ft_checksort(t_stack *s, int asc, int range)
{
	t_stack	*tmp;
	int		i;

	tmp = s;
	i = -1;
	if (asc == 1) // check for ascending order
	{
		while (++i < range && tmp->next)
		{
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	else if (asc == 0) // check for descending order
	{
		while (++i < range && tmp->next)
		{
			if (tmp->index < tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int	ft_stack_size(t_stack *top)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = top;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_stack	*ft_stack_middle(t_stack *start)
{
	int		mid;
	int		size;
	int		i;
	t_stack	*tmp;
	
	if (!start)
		return (NULL);
	mid = ft_stack_size(start) / 2;
	size = ft_stack_size(start);
	i = 0;
	tmp = start;
	if (size % 2 == 0)
		mid -= 1;
	while (i < mid)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
