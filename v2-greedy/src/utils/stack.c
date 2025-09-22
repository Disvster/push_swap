/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:36:52 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/17 21:17:16 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*create_stack_a(int ac, char **nav, long *tab)
{
	int			size;
	int			nbr;
	int			node_id;
	t_stack		*new_nd;
	t_stack		*temp;

	size = ac;
	temp = NULL;
	new_nd = NULL;
	while (size-- > 0)
	{
		nbr = ft_atoi(nav[size]);
		node_id = find_index(tab, ac, nbr);
		temp = stack_newnode(nbr, node_id);
		if (!temp)
			return (new_nd);
		if (new_nd)
			temp->next = new_nd;
		new_nd = temp;
	}
	return (new_nd);
}

t_stack	*stack_newnode(int value, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
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
		node = NULL;
		node = tmp;
	}
	lst = NULL;
}

int	ft_stack_size(t_stack *top)
{
	int		size;
	t_stack	*tmp;

	if (!top)
		return (0);
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
